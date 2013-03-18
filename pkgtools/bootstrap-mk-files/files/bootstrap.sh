#!/bin/sh
#
# Install mk-files for bootstrap.
#
# Expected environment:
# - CP
# - OPSYS
# - MK_DST
# - ROOT_GROUP
# - ROOT_USER
# - SED
# - SYSCONFDIR
#

: ${CP:=cp}
: ${SED:=sed}
: ${OPSYS:=`uname`}
: ${ROOT_USER:=`id -un 0`}
: ${ROOT_GROUP:=`id -gn "${ROOT_USER}"`}
: ${MK_DST:=/usr/local/share/mk}
: ${SYSCONFDIR:=/usr/local/etc}

for file in bsd.README bsd.dep.mk bsd.depall.mk bsd.doc.mk bsd.files.mk \
	bsd.hostprog.mk bsd.inc.mk bsd.info.mk bsd.kernobj.mk bsd.kinc.mk \
	bsd.kmod.mk bsd.lib.mk bsd.links.mk bsd.man.mk bsd.nls.mk \
	bsd.obj.mk bsd.prog.mk bsd.subdir.mk bsd.sys.mk sys.mk; do
	if [ -f mods/${OPSYS}.${file} ]; then
		${CP} mods/${OPSYS}.${file} ${MK_DST}/${file}
	else
		${CP} ${file} ${MK_DST}/${file}
	fi
done

subst_pattern='s|@ROOT_GROUP@|'${ROOT_GROUP}'|g;s|@ROOT_USER@|'${ROOT_USER}'|g;s|@SYSCONFDIR@|'${SYSCONFDIR}'|g'

if [ -f mods/${OPSYS}.bsd.own.mk.in ]; then
	${SED} -e "${subst_pattern}" mods/${OPSYS}.bsd.own.mk.in > ${MK_DST}/bsd.own.mk
else
	${SED} -e "${subst_pattern}" mods/bsd.own.mk.in > ${MK_DST}/bsd.own.mk
fi
