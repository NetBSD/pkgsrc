#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: radiusd.sh,v 1.2 2004/09/23 19:51:22 adrianp Exp $
#
# PROVIDE: radiusd
# REQUIRE: network
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="radiusd"
command="@PREFIX@/sbin/radiusd"
pidfile="@VARBASE@/run/radiusd/radiusd.pid"

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr

	load_rc_config $name
	run_rc_command "$1"
else
	echo -n ' ${name}'
	exec ${command} ${radiusd_flags} ${command_args}
fi
