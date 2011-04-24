#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ndtpd.sh,v 1.3 2011/04/24 13:47:45 shattered Exp $
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
rcvar="$name"
prog=@PREFIX@/sbin/ndtpd
pidfile=@NDTPD_RUNDIR@/ndtpd/ndtpd.pid

case $1 in
start)
	@ECHO@ "Starting ${name}."
	@MKDIR@ @NDTPD_RUNDIR@/ndtpd
	${prog} >/dev/null 2>&1 || {
		@ECHO@ "Configuration error?" >&2
		@ECHO@ "Try @PREFIX@/sbin/ndtpcheck" >&2
		exit 1
	}
	;;
stop)
	@ECHO@ "Stopping ${name}."
	if [ -f ${pidfile} ]; then
		pid=`@HEAD@ -1 ${pidfile}`
		kill -s TERM ${pid}
		@RM@ -fr @NDTPD_RUNDIR@/ndtpd
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
