#!/bin/sh
#
#	$NetBSD: exim.sh,v 1.2 1999/09/18 20:28:26 ad Exp $
#
if [ -x @PREFIX@/sbin/exim ] ; then
	echo -n ' exim'
	@PREFIX@/sbin/exim -bd -q15m
fi
