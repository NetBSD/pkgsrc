#!/bin/sh
#
# $NetBSD: rplayd.sh,v 1.3 2001/11/21 21:38:50 jlam Exp $
#
# PROVIDE: rplayd
# REQUIRE: DAEMON

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="rplayd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@CONFDIR@/rplay.conf"

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	${command} ${rplayd_flags} ${command_args}
fi
