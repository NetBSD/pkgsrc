#! /bin/sh
#
# $NetBSD: upsmon.sh,v 1.2 2001/11/21 21:38:55 jlam Exp $
#
# PROVIDE: upsmon
# REQUIRE: upsd

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="upsmon"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@NUT_CONFDIR@/${name}.conf"

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${upsmon_flags} ${command_args}
fi
