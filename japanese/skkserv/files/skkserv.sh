#!/bin/sh
#	$NetBSD: skkserv.sh,v 1.1.1.1 1999/12/24 03:19:23 itohy Exp $

if [ -f @PREFIX@/libexec/skkserv ]; then
	echo -n ' skkserv'
	PATH=@PREFIX@/libexec skkserv
fi
