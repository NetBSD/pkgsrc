#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dk-milter.sh,v 1.3 2005/07/20 20:03:40 tv Exp $
#
# PROVIDE: dkmilter
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="dkmilter"
rcvar=$name
command="@PREFIX@/sbin/dk-milter -P ${pidfile}"
pidfile="/var/run/${name}.pid"
command_args="-h -l -p /var/run/${name}.sock"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${dkmilter_flags} ${command_args}
fi
