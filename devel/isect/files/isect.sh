#!/bin/sh
#
# $NetBSD: isect.sh,v 1.1.1.1 1999/09/15 18:56:21 jlam Exp $
#

isdexecd=@PREFIX@/sbin/isdexecd
isectd=@PREFIX@/sbin/isectd

if [ -x ${isdexecd} -a -x ${isectd} ]; then
	@ECHO@ -n ' isect'
	${isdexecd} &
	${isectd} &
fi
exit 0
