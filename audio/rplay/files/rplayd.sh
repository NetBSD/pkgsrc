#!/bin/sh
#
# $NetBSD: rplayd.sh,v 1.2 2001/11/21 17:55:55 jlam Exp $
#
# PROVIDE: rplayd
# REQUIRE: DAEMON

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="rplayd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@CONFDIR@/rplay.conf"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	${command} ${rplayd_flags} ${command_args}
else
	load_rc_config $name
	run_rc_command "$1"
fi
