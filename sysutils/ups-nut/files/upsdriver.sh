#! /bin/sh
#
# $NetBSD: upsdriver.sh,v 1.1 2001/11/21 15:50:56 jlam Exp $
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
# Please refer to nutupsdrv(8) for more information about the arguments to
# pass to the UPS drivers.

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="upsdriver"
rcvar=$name
command="@PREFIX@/sbin/ups-drivers/${upsdriver_type}"
#
# XXX - We need a way to easily determine the pidfile, which is of the form
# XXX - @NUT_STATEDIR@/${updriver_type}-${tty}.pid
#
#pidfile="@NUT_STATEDIR@/${upsdriver_type}-${tty}.pid"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n " ${name}"
	${command} ${upsdriver_flags} ${command_args}
else
	load_rc_config $name
	run_rc_command "$1"
fi
