#!/bin/sh
#
# $NetBSD: geneweb.sh,v 1.2 2001/07/15 15:33:22 wulf Exp $
#
if [ -x @PREFIX@/libexec/gwd ]
then
	@PREFIX@/libexec/gwd \
		-hd @PREFIX@/share/geneweb \
		-bd @PREFIX@/share/geneweb/db \
		-dd @PREFIX@/share/doc/geneweb \
		-log /var/log/geneweb.log \
		-lang en \
		-robot_xcl 100,150 \
		-daemon
		/bin/echo -n ' gwd'
fi
exit 0
