#!/bin/sh
#
# $NetBSD: samba.sh,v 1.2 2000/05/02 15:24:09 jlam Exp $

smbd=@PREFIX@/sbin/smbd
nmbd=@PREFIX@/sbin/nmbd

if [ -f ${smbd} ]; then
	@ECHO@ -n ' samba'
	${smbd} -D
	${nmbd} -D
fi
