#!/bin/sh
# $NetBSD: arlad.sh,v 1.1.1.1 2000/06/08 15:56:28 wennmach Exp $
if [ -f @PREFIX@/sbin/arlad ]; then
	echo -n " arlad"
	@PREFIX@/sbin/arlad -z /dev/xfs0
fi
