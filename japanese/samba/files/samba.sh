#!/bin/sh
#
# $NetBSD: samba.sh,v 1.1.1.1 2000/08/30 17:29:44 kei Exp $

smbd=@PREFIX@/sbin/smbd
nmbd=@PREFIX@/sbin/nmbd

if [ -f ${smbd} ]; then
	@ECHO@ -n ' samba'
	${smbd} -D
	${nmbd} -D
fi
