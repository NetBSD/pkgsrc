#! /bin/sh
#
# $NetBSD: upslog.sh,v 1.1 2001/11/21 15:50:56 jlam Exp $
#
# PROVIDE: upslog
# REQUIRE: upsd
#
# You will need to set some variables in /etc/rc.conf to start upslog
# properly, e.g.
#
# upslog=YES
# upslog_flags="smartups@localhost /var/log/ups 60"
#
# Please refer to upslog(8) for more information about the arguments to pass
# to upslog.

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="upslog"
rcvar="${name}"
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@CONFDIR@/nut/${name}.conf"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n " ${name}"
	${command} ${upsmon_flags} ${command_args}
else
	load_rc_config $name
	run_rc_command "$1"
fi
