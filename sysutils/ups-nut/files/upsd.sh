#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upsd.sh,v 1.5 2002/09/20 02:02:01 grant Exp $
#
# PROVIDE: upsd
# REQUIRE: upsdriver

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="upsd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@NUT_CONFDIR@/${name}.conf"
pidfile="@NUT_STATEDIR@/${name}.pid"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${upsd_flags} ${command_args}
fi
