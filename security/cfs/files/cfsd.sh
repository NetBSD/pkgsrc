#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cfsd.sh,v 1.4 2003/07/31 10:05:53 jmmv Exp $
#
# PROVIDE: cfsd
# REQUIRE: mountd
#
# To start cfsd at startup, copy this script to /etc/rc.d and set
# cfs=YES in /etc/rc.conf.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="cfsd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="> /dev/null 2>&1"
required_vars="mountd rpcbind"

if [ -f /etc/rc.subr ]; then
	load_rc_config "$name"
	run_rc_command "$1"
else
	printf " $name"
	eval ${command} ${cfsd_flags} ${command_args}
fi
