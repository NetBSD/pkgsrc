#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: snmpd.sh,v 1.5 2011/10/22 07:33:34 shattered Exp $
#
# PROVIDE: snmpd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

: ${snmpd_flags:="-Ls d"}		# log using syslog LOG_DAEMON

name="snmpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
command_args="-p ${pidfile}"

if [ -f @PKG_SYSCONFDIR@/snmpd.conf ]; then
	command_args="${command_args} -c @PKG_SYSCONFDIR@/snmpd.conf"
fi

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]; then
        load_rc_config $name
        run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${snmpd_flags} ${command_args}
fi
