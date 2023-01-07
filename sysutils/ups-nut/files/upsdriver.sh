#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upsdriver.sh,v 1.9.34.1 2023/01/07 16:07:59 gdt Exp $
#
# PROVIDE: upsdriver
# REQUIRE: NETWORK syslogd mountcritremote
#
# The standard approach is to leave "upsdriver_type" unset, so that
# upsdrvctl is used to start and stop the driver(s).  (Note that a
# system might have more than one UPS, and upsdrvctl should support
# this.)  See nutupsdrv(8), but upsdrvctl will invoke the driver
# properly.
#
# An alternative is to set the driver type and flags.  This only works
# for a single driver.  This approach is deprecated and may be removed.
#
# upsdriver=YES
#	upsdriver_type="newapc"
#	upsdriver_flags="-a smartups"

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="upsdriver"
rcvar=$name

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
fi

if [ "${upsdriver_type:-upsdrvctl}" = "upsdrvctl" ]; then
	ctl_command="@PREFIX@/sbin/upsdrvctl"
	required_files="@NUT_CONFDIR@/ups.conf"
	start_cmd="${ctl_command} start"
	stop_cmd="${ctl_command} stop"
	# XXX implement status after upsdrvctl does
else
	command="@PREFIX@/libexec/nut/${upsdriver_type}"
	# XXX Restructure upsname into variable, but really just
	# delete this option.
	#upsname=`echo $upsdriver_flags | sed -e 's/^-a //'
	#pidfile="@NUT_STATEDIR@/${upsdriver_type}-${upsname}.pid"
fi

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
