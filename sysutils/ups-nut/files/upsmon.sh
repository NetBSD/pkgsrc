#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upsmon.sh,v 1.4 2002/09/20 02:02:01 grant Exp $
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
