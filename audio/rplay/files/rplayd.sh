#!/bin/sh
#
# $NetBSD: rplayd.sh,v 1.1 2000/01/26 22:11:36 jlam Exp $

if [ -x @PREFIX@/sbin/rplayd ]; then
	echo -n ' rplayd';	@PREFIX@/sbin/rplayd
fi
