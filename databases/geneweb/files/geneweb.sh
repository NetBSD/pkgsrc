#!/bin/sh
#
# $NetBSD: geneweb.sh,v 1.1.1.1 2000/07/25 13:02:08 wulf Exp $
#
if [ -x @PREFIX@/libexec/gwd ]
then
	@PREFIX@/libexec/gwd \
		-hd @PREFIX@/share/geneweb \
		-bd @PREFIX@/share/geneweb \
		-dd @PREFIX@/share/doc/geneweb \
		-log /var/log/geneweb.log \
		-lang en \
		-robot_xcl 100,150 \
		-daemon
		/bin/echo -n ' gwd'
fi
exit 0
