#!/bin/sh
#
# $NetBSD: ndtpd.sh,v 1.1.1.1 2002/03/15 07:19:58 uebayasi Exp $
#
# PROVIDE: ndtpd
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# To start ndtpd at startup, copy this script to /etc/rc.d and set
# ndtpd=YES in /etc/rc.conf.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="ndtpd"
rcvar=$name
prog="@PREFIX@/sbin/ndtpd"
pidfile=@NDTPD_RUNDIR@/ndtpd/ndtpd.pid

case $1 in
start)
	{ @ECHO@ "Starting ${name}."; ${prog} >/dev/null 2>&1; } || {
		@ECHO@ "Configuration error?" >&2
		@ECHO@ "Try @PREFIX@/sbin/ndtpdcheck" >&2
		exit 1
	}
	;;
stop)
	if [ -f ${pidfile} ]; then
		pid=`@HEAD@ -1 ${pidfile}`
		@ECHO@ "Stopping ${name}."
		kill -s TERM ${pid}
	else
		@ECHO@ "${name} not running?"
		exit 1
	fi
	;;
*)
	@ECHO@ "Usage: $0 [start|stop]" 1>&2
	exit 1
	;;
esac

exit 0
