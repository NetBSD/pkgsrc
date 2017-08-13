#!/bin/sh
# $Id: pbulk.sh,v 1.3.14.1 2017/08/13 18:45:27 bsiegert Exp $
set -e

usage="usage: ${0##*/} [-lun] [-c mk.conf.fragment] [-d nodes]"

while getopts lunc:d: opt; do
    case $opt in
	l) limited=yes;;
	u) unprivileged=yes;;
	n) native=yes;;
	c) mk_fragment="${OPTARG}";;
	d) nodes="${OPTARG}";;
	\?) echo "$usage" 1>&2; exit 1;;
    esac
done
shift $(expr $OPTIND - 1)
if [ $# != 0 ]; then echo "$usage" 1>&2; exit 1; fi

: ${TMPDIR:=/tmp}

## settings for unprivileged build:
if [ -n "$unprivileged" ]; then
: ${PBULKPREFIX:=${HOME}/pbulk}
: ${PKGSRCDIR:=${HOME}/pkgsrc}
: ${PREFIX:=${HOME}/pkg}
: ${PACKAGES:=${HOME}/packages}
: ${BULKLOG:=${HOME}/bulklog}
fi

##
: ${PBULKPREFIX:=/usr/pbulk}
: ${PBULKWORK:=${TMPDIR}/work-pbulk}

: ${PACKAGES:=/mnt/packages}
: ${BULKLOG:=/mnt/bulklog}

# almost constant:
: ${PKGSRCDIR:=/usr/pkgsrc}

# Do it early since adding it after it fails is problematic:
if [ ! -n "$unprivileged" ]; then
case "$(uname)" in
NetBSD)
if ! id pbulk; then user add -m -g users pbulk; fi
;;
FreeBSD)
if ! id pbulk; then
    if ! pw groupshow users; then pw groupadd users; fi
    pw useradd pbulk -m -g users
fi
;;
*)
if ! id pbulk; then echo "user \"pbulk\" is absent"; exit 1; fi
;;
esac
fi

# Deploying pbulk packages:
# - bootstrapping
cat >${TMPDIR}/pbulk.mk <<EOF
PKG_DEVELOPER=	yes
EOF

${PKGSRCDIR}/bootstrap/bootstrap \
  ${unprivileged:+--unprivileged} \
  --mk-fragment=${TMPDIR}/pbulk.mk \
  --prefix=${PBULKPREFIX} \
  --workdir=${PBULKWORK}
rm -rf ${PBULKWORK}
rm -f ${TMPDIR}/pbulk.mk

# - installing pbulk
(cd ${PKGSRCDIR}/pkgtools/pbulk && PACKAGES=${TMPDIR}/packages-pbulk WRKOBJDIR=${TMPDIR}/obj-pbulk ${PBULKPREFIX}/bin/bmake install)
rm -rf ${TMPDIR}/obj-pbulk
rm -rf ${TMPDIR}/packages-pbulk

## cleaning after all this:
# rm -rf ${PBULKPREFIX}

cat >> ${PBULKPREFIX}/etc/pbulk.conf.over <<EOF
#
# Overriding default settings:
master_mode=no
bootstrapkit=${PACKAGES}/bootstrap.tar.gz
bulklog=${BULKLOG}
packages=${PACKAGES}
mail=:
rsync=:
EOF
# base_url needs to be adjusted, although the pbulk code should
# not need to know it at all, maybe except for generating the
# mail that the report has been completed.

# Speed scan phase up for repeated runs:
cat >> ${PBULKPREFIX}/etc/pbulk.conf.over <<EOF
reuse_scan_results=yes
EOF

# Quotes around "EOF" are important below
# (they prevent variable expansion in here-document):
cat >> ${PBULKPREFIX}/etc/pbulk.conf.over <<"EOF"
# Don't forget to recompute dependent settings:
loc=${bulklog}/meta
EOF

if [ -n "$limited" ]; then
cat >> ${PBULKPREFIX}/etc/pbulk.conf.over <<EOF
# Limited list build overrides:
limited_list=${PBULKPREFIX}/etc/pbulk.list
EOF

# generate minimal list
cat > ${PBULKPREFIX}/etc/pbulk.list <<EOF
pkgtools/digest
EOF
fi

if [ -n "$unprivileged" ]; then
# Unprivileged bulk build:
cat >> ${PBULKPREFIX}/etc/pbulk.conf.over <<EOF
# Unprivileged bulk build overrides:
unprivileged_user=$(id -un)
pkgsrc=${PKGSRCDIR}
prefix=${PREFIX}
varbase=${PREFIX}/var
pkgdb=${PREFIX}/var/db/pkg
EOF
elif [ -n "${PREFIX}" ]; then
# Non-default prefix:
cat >> ${PBULKPREFIX}/etc/pbulk.conf.over <<EOF
# Non-default prefix overrides:
prefix=${PREFIX}
varbase=${PREFIX}/var
pkgdb=${PREFIX}/var/db/pkg
EOF
fi

# Quotes around "EOF" are important below
# (they prevent variable expansion in here-document):
cat >> ${PBULKPREFIX}/etc/pbulk.conf.over <<"EOF"
# Don't forget to recompute dependent settings:
make=${prefix}/bin/bmake
EOF

if [ -n "$native" ]; then
# Native bulk build (native make, no bootstrap kit needed):
cat >> ${PBULKPREFIX}/etc/pbulk.conf.over <<EOF
# Native bulk build overrides:
make=/usr/bin/make
bootstrapkit=
EOF
fi

# Distributed bulk build:
if [ -n "$nodes" ]; then
master_node="${nodes%% *}"
slave_nodes="${nodes#* }"
cat >> ${PBULKPREFIX}/etc/pbulk.conf.over <<EOF
# Distributed bulk build overrides:
master_mode=yes
master_ip="${master_node}"
scan_clients="${slave_nodes}"
build_clients="${slave_nodes}"
EOF
cat >> ${PBULKPREFIX}/etc/pbulk.conf.over <<"EOF"
# Recompute dependent settings:
master_port_scan=${master_ip}:2001
master_port_build=${master_ip}:2002
EOF
fi

cat ${PBULKPREFIX}/etc/pbulk.conf ${PBULKPREFIX}/etc/pbulk.conf.over > ${PBULKPREFIX}/etc/pbulk.conf.new
cp ${PBULKPREFIX}/etc/pbulk.conf ${PBULKPREFIX}/etc/pbulk.conf.bak
mv ${PBULKPREFIX}/etc/pbulk.conf.new ${PBULKPREFIX}/etc/pbulk.conf

# Bootstrapping
if [ -n "$native" ]; then
if [ -n "$mk_fragment" ]; then cat "$mk_fragment" > /etc/mk.conf; fi
else
# Ensure that the directory for bootstrap kit exists:
mkdir -p ${PACKAGES}

# Creating the bootstrap kit
${PKGSRCDIR}/bootstrap/bootstrap \
  ${unprivileged:+--unprivileged} \
  ${PREFIX:+--prefix=${PREFIX}} \
  ${mk_fragment:+--mk-fragment="$mk_fragment"} \
  --workdir=${TMPDIR}/work \
  --gzip-binary-kit=${PACKAGES}/bootstrap.tar.gz
rm -rf ${TMPDIR}/work
rm -f ${TMPDIR}/mk.conf.inc
fi
# Keep "packages" in pbulk.conf and "PACKAGES" in mk.conf fragment in sync.

# Final preparations:
mkdir -p ${PACKAGES}/All
if [ ! -n "$unprivileged" ]; then
chown pbulk:"$(id -gn pbulk)" ${PACKAGES}
fi

# Let's start:
#PACKAGES=${PACKAGES} WRKOBJDIR=${TMPDIR} ${PBULKPREFIX}/bin/bulkbuild
