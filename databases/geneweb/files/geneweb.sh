#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: geneweb.sh,v 1.3 2003/01/19 12:34:46 grant Exp $
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
