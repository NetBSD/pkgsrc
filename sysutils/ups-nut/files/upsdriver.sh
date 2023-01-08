#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upsdriver.sh,v 1.12 2023/01/08 01:32:55 gdt Exp $
#
# PROVIDE: upsdriver
# REQUIRE: NETWORK syslogd mountcritremote
# KEYWORD: shutdown
#
# This script calls upsdrvctl to start and stop the driver(s).  (Note
# that a system might have more than one UPS, and upsdrvctl should
# support this.)  See nutupsdrv(8), but upsdrvctl will invoke the
# driver properly.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="upsdriver"
rcvar=$name

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
fi

ctl_command="@PREFIX@/sbin/upsdrvctl"
required_files="@NUT_CONFDIR@/ups.conf"
start_cmd="${ctl_command} start"
stop_cmd="${ctl_command} stop"
# XXX implement status after upsdrvctl does

if [ -f /etc/rc.subr ]; then
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	if [ -n "${start_cmd}" ]; then
		${start_cmd}
	else
		${command} ${upsdriver_flags} ${command_args}
	fi
fi
