#! /bin/sh
#
# $NetBSD: upsdriver.sh,v 1.3 2001/11/21 21:38:55 jlam Exp $
#
# PROVIDE: upsdriver
# REQUIRE: NETWORK syslogd mountcritremote
#
# You will need to set some variables in /etc/rc.conf to start upslog
# properly, e.g.
#
# upsdriver=YES
#	upsdriver_type="newapc"
#	upsdriver_flags="-a smartups"
#
# If "upsdriver_type" is unset, then use "upsdrvctl" to control the UPS
# drivers.  Please refer to nutupsdrv(8) for more information about the
# arguments to pass to the UPS drivers.

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="upsdriver"
rcvar=$name

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
fi

if [ "${upsdriver_type:-upsdrvctl}" = "upsdrvctl" ]
then
	ctl_command="@PREFIX@/sbin/upsdrvctl"
	required_files="@NUT_CONFDIR@/ups.conf"
	start_cmd="${ctl_command} start"
	stop_cmd="${ctl_command} stop"
else
	command="@PREFIX@/sbin/ups-drivers/${upsdriver_type}"
	#
	# XXX - We need a way to easily determine the pidfile, which is of
	# XXX - the form @NUT_STATEDIR@/${updriver_type}-${tty}.pid
	#
	#pidfile="@NUT_STATEDIR@/${upsdriver_type}-${tty}.pid"
fi

if [ -e /etc/rc.subr ]
then
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	if [ -n "${start_cmd}" ]
	then
		${start_cmd}
	else
		${command} ${upsdriver_flags} ${command_args}
	fi
fi
