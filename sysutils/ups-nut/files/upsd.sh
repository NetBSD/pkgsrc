#! /bin/sh
#
# $NetBSD: upsd.sh,v 1.1 2001/11/21 15:50:56 jlam Exp $
#
# PROVIDE: upsd
# REQUIRE: upsdriver

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="upsd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@NUT_CONFDIR@/${name}.conf"
pidfile="@NUT_STATEDIR@/${name}.pid"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n " ${name}"
	${command} ${upsd_flags} ${command_args}
else
	load_rc_config $name
	run_rc_command "$1"
fi
