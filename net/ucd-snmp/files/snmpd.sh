#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: snmpd.sh,v 1.9 2003/07/30 21:05:00 jmmv Exp $
#
# PROVIDE: snmpd
# REQUIRE: DAEMON LOGIN network
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="snmpd"
rcvar="${name}"
pidfile="/var/run/snmpd.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
command="@PREFIX@/sbin/snmpd"
command_args="-s -P ${pidfile} -A -c @PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config "$name"
	run_rc_command "$1"
else
	printf " $name"
	${command} ${snmpd_flags} ${command_args}
fi
