#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: isect.sh,v 1.2 2003/01/19 12:54:33 grant Exp $
#

isdexecd=@PREFIX@/sbin/isdexecd
isectd=@PREFIX@/sbin/isectd

if [ -x ${isdexecd} -a -x ${isectd} ]; then
	@ECHO@ -n ' isect'
	${isdexecd} &
	${isectd} &
fi
exit 0
