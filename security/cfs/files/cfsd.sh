#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cfsd.sh,v 1.6 2004/08/03 04:35:42 tv Exp $
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
