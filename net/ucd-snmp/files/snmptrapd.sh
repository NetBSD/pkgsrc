#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: snmptrapd.sh,v 1.7 2003/07/30 21:05:00 jmmv Exp $
#
# PROVIDE: snmpd
# REQUIRE: DAEMON LOGIN network
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="snmptrapd"
rcvar="${name}"
pidfile="/var/run/snmptrapd.pid"
command="@PREFIX@/sbin/snmptrapd"
command_args="-s -l 1 -u ${pidfile}"

if [ -f /etc/rc.subr ]; then
	load_rc_config "$name"
	run_rc_command "$1"
else
	printf " $name"
	${command} ${snmptrapd_flags} ${command_args}
fi
