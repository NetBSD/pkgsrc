#!/bin/sh
#
# $NetBSD: rplayd.sh,v 1.5 2002/02/05 06:04:36 jlam Exp $
#
# PROVIDE: rplayd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="rplayd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/rplay.conf"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	${command} ${rplayd_flags} ${command_args}
fi
