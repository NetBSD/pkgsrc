#! /bin/sh

# $NetBSD: gimme.sh,v 1.1.1.1 2015/11/22 21:57:38 agc Exp $

# Copyright (c) 2015 Alistair Crooks <agc@NetBSD.org>
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

# small script to be used to provide binary packages
# args:
# -c	use current host to provide base operating system
# -d	use the sets in this dir as base operating system
# -v	be verbose in operation

current=false
distribdir=''
while [ $# -gt 0 ]; do
	case "$1" in
	-c)	current=true ;;
	-d)	distribdir="$2"; shift ;;
	-v)	set -x ;;
	*)	break ;;
	esac
	shift
done

# check whether sudo is needed
case "$(id -u)" in
0)	sudo="" ;;
*)	sudo=sudo ;;
esac

# function to clean up stuff
cleanup() {
	case "${conf}" in
	"")	;;
	*)	if [ -f /root/pkg_comp/${conf} ]; then
			${sudo} rm -f /root/pkg_comp/${conf}
		fi
		;;
	esac
	if ${current}; then
		case "${distribdir}" in
		"")	;;
		*)	if [ -d ${distribdir} ]; then
				${sudo} rm -rf ${distribdir}
			fi
			;;
		esac
	fi
}

trap cleanup 9 15

pkgsdir=/usr/pkgsrc/packages/All

conf=gimme.$$

# don't need the chatty message about editing by hand
${sudo} pkg_comp -c ${conf} maketemplate >/dev/null

base_files='
./altroot
./bin
./lib
./libdata
./libexec
./rescue
./sbin
./usr/bin
./usr/lib
./usr/libdata
./usr/libexec
./usr/mdec
./usr/sbin
./var/chroot
./var/db
./var/games
./var/heimdal
./var/log/rdist
./var/mail
./var/msgs
./var/preserve
./var/quotas
./var/run
./var/rwho
./var/shm
./var/spool
./var/tmp/vi.recover
./var/tpm
./var/www
./var/yp/binding
'

etc_files='
.cshrc
.profile
boot.cfg
./dev/MAKEDEV
./dev/MAKEDEV.local
./etc
./var/at/at.deny
./var/crash/minfree
./var/cron/tabs/root
./var/games
./var/log
./var/msgs
./var/run/utmp
./var/run/utmpx
./var/yp/Makefile.yp
./var/yp/nicknames
'

# current means to use current os as basis for compilation
if ${current}; then
	echo "creating temporary set files for operating system"
	distribdir=$(${sudo} mktemp -d /tmp/gimmesets.XXXXXX)
	${sudo} mkdir -p ${distribdir}/binary/sets
	tmptmpdir=$(${sudo} mktemp -d /tmp/tmptmp.XXXXXX)
	${sudo} chmod 1777 ${tmptmpdir}
	vartmptmpdir=$(${sudo} mktemp -d /tmp/tmptmp.XXXXXX)
	${sudo} chmod 1777 ${vartmptmpdir}
	(cd / && ${sudo} tar -czf ${distribdir}/binary/sets/base.tgz -s '|'./${tmptmpdir}'|./tmp|' -s '|'./${vartmptmpdir}'|./var/tmp|' ${base_files} ./${tmptmpdir} ./${vartmptmpdir})
	(cd / && ${sudo} tar -czf ${distribdir}/binary/sets/comp.tgz ./usr/include)
	(cd / && ${sudo} tar -czf ${distribdir}/binary/sets/etc.tgz ${etc_files})
	(cd / && ${sudo} tar -czf ${distribdir}/binary/sets/kern-GENERIC.tgz ./netbsd)
	(cd / && ${sudo} tar -czf ${distribdir}/binary/sets/text.tgz ./usr/share)
	(cd / && ${sudo} tar -czf ${distribdir}/binary/sets/xbase.tgz ./usr/X11R7/bin ./usr/X11R7/lib ./usr/X11R7/man ./usr/libdata/debug/usr/X11R7)
	(cd / && ${sudo} tar -czf ${distribdir}/binary/sets/xcomp.tgz ./usr/X11R7/include)
	(cd / && ${sudo} tar -czf ${distribdir}/binary/sets/xetc.tgz ./etc/X11 ./etc/fonts ./etc/rc.d/fccache ./etc/rc.d/xdm ./etc/rc.d/xfs)
	(cd / && ${sudo} tar -czf ${distribdir}/binary/sets/xfont.tgz ./usr/X11R7/lib/X11/fonts)
	(cd / && ${sudo} tar -czf ${distribdir}/binary/sets/xserver.tgz ./usr/X11R7/bin/X ./usr/X11R7/bin/Xnest ./usr/X11R7/bin/Xorg ./usr/X11R7/bin/Xvfb ./usr/X11R7/share)
	${sudo} rm -rf ${tmptmpdir} ${vartmptmpdir}
fi

# set where the binary sets are
case "${distribdir}" in
"")	;;
*)	
	tmp=$(mktemp /tmp/gimme.XXXXXX)
	sed -e 's|^DISTRIBDIR=.*|DISTRIBDIR='${distribdir}'|' /root/pkg_comp/${conf}.conf > ${tmp} &&
		${sudo} mv ${tmp} /root/pkg_comp/${conf}.conf
	;;
esac

# sanity check for distribdir
if [ ! -f ${distribdir}/binary/sets/etc.tgz ]; then
	t1=${distribdir##/binary/sets}
	if [ -f ${t1}/etc.tgz ]; then
		echo "Info: no need to specify "/binary/sets" on end of distribdir"
		distribdir=${t1}
	else
		echo "can't find binary sets in ${distribdir}" >&2
		cleanup
		exit 1
	fi
fi

# use pkg_comp to make the packages
${sudo} pkg_comp -c ${conf} makeroot
for p in $@; do
	${sudo} pkg_comp -c ${conf} build ${p}
	ls -al ${pkgsdir}/${p}*
done
${sudo} pkg_comp -c ${conf} removeroot

cleanup
