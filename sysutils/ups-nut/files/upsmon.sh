#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upsmon.sh,v 1.7 2006/08/15 12:07:15 ghen Exp $
#
# PROVIDE: upsmon
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="upsmon"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"
pidfile="@NUT_STATEDIR@/${name}.pid"
required_files="@NUT_CONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${upsmon_flags} ${command_args}
fi
