#! /bin/sh
#
# $NetBSD: upsmon.sh,v 1.3 2002/02/05 06:04:42 jlam Exp $
#
# PROVIDE: upsmon
# REQUIRE: upsd

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="upsmon"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@NUT_CONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${upsmon_flags} ${command_args}
fi
