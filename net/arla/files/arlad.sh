#!/bin/sh
# $NetBSD: arlad.sh,v 1.2 2001/08/09 13:48:59 wennmach Exp $
#
# start script for arlad (for NetBSD earlier than 1.5)

if [ -f @PREFIX@/libexec/arlad ]; then
	echo -n " arlad"
	@PREFIX@/libexec/arlad -z /dev/xfs0
fi
