#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: snmptrapd.sh,v 1.2 2003/09/12 12:07:19 uebayasi Exp $
#
# PROVIDE: snmptrapd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="snmptrapd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
# XXX this should include '-S 1' to explicitly set LOG_LOCAL1, but if
# it's there snmptrapd blows up saying "no syslog facility specified"
# and then printing a usage message (and the old -l complains too!)
#   --woods
#
snmptrapd_flags="-s"	# log using syslog w/ facility LOG_LOCAL1
command_args="-u ${pidfile}"

if [ -f @PKG_SYSCONFDIR@/snmptrapd.conf ]; then
	command_args="${command_args} -c @PKG_SYSCONFDIR@/snmptrapd.conf"
fi

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]; then
        load_rc_config $name
        run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${snmptrapd_flags} ${command_args}
fi
