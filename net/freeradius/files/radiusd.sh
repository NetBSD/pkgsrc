#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: radiusd.sh,v 1.1.8.1 2004/10/19 12:51:58 agc Exp $
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
