#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upsmon.sh,v 1.5 2003/01/26 00:48:24 fredb Exp $
#
# PROVIDE: upsmon
# REQUIRE: upsd
# KEYWORD: shutdown

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
