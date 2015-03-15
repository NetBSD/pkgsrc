#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dk-milter.sh,v 1.6 2015/03/15 15:28:58 mef Exp $
#
# PROVIDE: dkmilter
# REQUIRE: DAEMON
# BEFORE: mail

dkmilter_flags="-h -l -p /var/run/dkmilter.sock"

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="dkmilter"
rcvar=$name
command="@PREFIX@/sbin/dk-milter"
pidfile="/var/run/${name}.pid"
command_args="-P ${pidfile}"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${dkmilter_flags} ${command_args}
fi
