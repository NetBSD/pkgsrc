#!/bin/sh
#
# $NetBSD: exim.sh,v 1.1 1999/09/07 13:21:02 ad Exp $
#
if [ -x @PREFIX@/sbin/exim ] ; then
	echo -n ' exim'
	@PREFIX@/sbin/exim -bd -q15m
fi
