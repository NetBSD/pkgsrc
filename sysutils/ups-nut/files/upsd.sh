#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upsd.sh,v 1.9 2023/01/08 01:14:23 gdt Exp $
#
# PROVIDE: upsd
# REQUIRE: upsdriver
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="upsd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@NUT_CONFDIR@/${name}.conf"
pidfile="@NUT_STATEDIR@/${name}.pid"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${upsd_flags} ${command_args}
fi
