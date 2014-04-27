#! /bin/sh

# $NetBSD: genpkgng.sh,v 1.1.1.1 2014/04/27 00:10:34 agc Exp $

# Copyright (c) 2014 Alistair Crooks <agc@NetBSD.org>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

# script to convert from a pkgsrc package to a pkgng one
# usage: genpkgng [-v] binpkg...

# small function to get information from build info
getvar() {
	echo "$1" | awk '/^'$2'=/ { sub("'$2'=", ""); print }'
}

# process command line args
while [ $# -gt 0 ]; do
	case "$1" in
	-v)	set -x ;;
	*)	break ;;
	esac
	shift
done

here=$(pwd)

while [ $# -gt 0 ]; do
	binpkg=$1
	echo "Converting ${binpkg}"

	# get the package metadata from the pkgsrc binary package
	pkgname=${binpkg%.tgz}
	buildinfo=$(pkg_info -B ${binpkg})
	name=${binpkg%-*}
	name=${name##*/}
	origin=$(getvar "${buildinfo}" PKGPATH)
	version=${binpkg##*-}
	version=${version%.tgz}
	comment=$(pkg_info -qc ${binpkg})
	os=$(getvar "${buildinfo}" OPSYS)
	os_version=$(getvar "${buildinfo}" OS_VERSION)
	os_version=${os_version%%.*}
	machine_arch=$(getvar "${buildinfo}" MACHINE_ARCH | awk '{ sub("_", ":"); print }')
	arch="${os}:${os_version}:${machine_arch}"
	maintainer=$(getvar "${buildinfo}" MAINTAINER)
	prefix=$(getvar "${buildinfo}" LOCALBASE)
	www=$(getvar "${buildinfo}" HOMEPAGE)
	licenselogic="single"
	flatsize="$(pkg_info -qs ${binpkg})"
	desc="$(pkg_info -qd ${binpkg} | awk '{ gsub("\"", "\\\""); printf("%s\\\\n", $0) }')"
	categories=$(getvar "${buildinfo}" CATEGORIES)
	categories=$(echo "${categories}" | awk 'NF == 1 { printf("\"%s\"", $0) } NF > 1 { gsub("[ ]+", "\",\""); printf("\"%s\"", $0) }' )

	# make the temp dir
	newpkgdir=$(mktemp -d -t genpkgng)
	mkdir ${newpkgdir}/metadata ${newpkgdir}/archive

	# create the basis for the compact and large manifests
	(cd ${newpkgdir} && tar -s'|^[a-z]|archive/usr/pkg/&|' -s'|^\+|metadata/&|' -xzf ${here}/${binpkg})
	awk -v name="${name}" -v origin="${origin}" -v version="${version}" -v arch="${arch}" \
		-v comment="${comment}" -v arch="${arch}" -v maintainer="${maintainer}" \
		-v prefix="${prefix}" -v www="${www}" -v licenselogic="${licenselogic}" \
		-v flatsize="${flatsize}" -v desc="${desc}" -v categories="${categories}" \
	'BEGIN {
		printf("{\"name\":\"%s\",\"origin\":\"%s\",\"version\":\"%s\",\"comment\":\"%s\",\"arch\":\"%s\",\"maintainer\":\"%s\",\"prefix\":\"%s\",\"www\":\"%s\",\"licenselogic\":\"%s\",\"flatsize\":%s,\"desc\":\"%s\",\"categories\":[%s]",
			name, origin, version, comment, arch, maintainer, prefix, www, licenselogic, flatsize, desc, categories)
	}' > ${newpkgdir}/archive/+COMPACT_MANIFEST
	cp  ${newpkgdir}/archive/+COMPACT_MANIFEST ${newpkgdir}/archive/+MANIFEST
	echo -n '}' >> ${newpkgdir}/archive/+COMPACT_MANIFEST

	# copy metadata information
	mkdir -p ${newpkgdir}/archive/${prefix}/etc/metadata/${pkgname}
	cp ${newpkgdir}/metadata/+BUILD_VERSION ${newpkgdir}/archive/${prefix}/etc/metadata/${pkgname}/build_version
	cp ${newpkgdir}/metadata/+BUILD_INFO ${newpkgdir}/archive/${prefix}/etc/metadata/${pkgname}/build_info

	# add the files and digests to the manifest
	echo -n ',"files":{' >> ${newpkgdir}/archive/+MANIFEST
	sep=""
	for f in $(pkg_info -qL ${binpkg}) ${prefix}/etc/metadata/${pkgname}/build_version ${prefix}/etc/metadata/${pkgname}/build_info; do
		if [ -f ${newpkgdir}/archive/${f} ]; then
			# redirect digest input so that filenames are omitted
			echo -n "${sep}\"${f}\":\"$(digest sha256 < ${newpkgdir}/archive/${f})\"" >> ${newpkgdir}/archive/+MANIFEST
		fi
		sep=","
	done
	echo -n '},"directories":{' >> ${newpkgdir}/archive/+MANIFEST
	directories="$(awk '/^[^+@]/ { match($0, ".*/"); a[substr($0, 1, RLENGTH-1)] = 1 } END { for (i in a) print i }' ${newpkgdir}/metadata/+CONTENTS)"
	sep=""
	for d in ${directories} etc/metadata etc/metadata/${pkgname}; do
		if [ -d ${newpkgdir}/archive/${prefix}/${d} ]; then
			echo -n "${sep}\"${prefix}/${d}\":\"n\"" >> ${newpkgdir}/archive/+MANIFEST
		fi
		sep=","
	done
	echo -n '}' >> ${newpkgdir}/archive/+MANIFEST
	if [ -f ${newpkgdir}/metadata/+INSTALL ]; then
		echo -n ",\"scripts\":{\"pre-install\":\"cd ${prefix}\",\"post-install\":\"cd ${prefix}\",\"pre-install\":\"cd ${prefix}\",\"post-install\":\"cd ${prefix}\"}" >> ${newpkgdir}/archive/+MANIFEST
	fi
	echo -n '}' >> ${newpkgdir}/archive/+MANIFEST

	# now make the pkgng binary package
	cp @MTREE_DIR_DIR@/MTREE_DIRS ${newpkgdir}/archive/+MTREE_DIRS
	(cd ${newpkgdir}/archive && tar -czf ${here}/${pkgname}.txz *)
	ls -l ${pkgname}.txz 
	rm -rf ${newpkgdir}
	shift
done

exit 0
