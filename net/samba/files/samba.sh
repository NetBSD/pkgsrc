#!/bin/sh
#
# $NetBSD: samba.sh,v 1.1 1999/11/16 21:01:05 jlam Exp $

smbd=__PREFIX__/sbin/smbd
nmbd=__PREFIX__/sbin/nmbd

if [ -f ${smbd} ]; then
	__ECHO__ -n ' samba'
	${smbd} -D
	${nmbd} -D
fi
