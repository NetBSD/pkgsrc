#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dkim-milter.sh,v 1.1.1.1 2005/10/27 19:49:07 minskim Exp $
#
# PROVIDE: dkimmilter
# REQUIRE: DAEMON
# BEFORE: mail

dkimmilter_flags="-h -l -p /var/run/dkimmilter.sock"

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="dkimmilter"
rcvar=$name
command="@PREFIX@/sbin/dkim-milter"
pidfile="/var/run/${name}.pid"
command_args="-P ${pidfile}"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${dkimmilter_flags} ${command_args}
fi
