#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: radiusd.sh,v 1.1 2003/07/30 14:50:10 jmmv Exp $
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
pidfile="/var/run/radiusd/radiusd.pid"

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr

	load_rc_config $name
	run_rc_command "$1"
else
	echo -n ' ${name}'
	exec ${command} ${smbd_flags} ${command_args}
fi
