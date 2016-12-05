#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: trytond.sh,v 1.1 2016/12/05 22:21:41 rodent Exp $
#
# PROVIDE: trytond
# REQUIRE: DAEMON

. /etc/rc.subr

name="trytond"
rcvar=${name}
command="@PREFIX@/bin/${name}@PYVERSSUFFIX@"
required_files="@PKG_SYSCONFDIR@/tryton/${name}.conf"
pidfile="@VARBASE@/run/${name}.pid"

command_args="-c ${required_files} --pidfile ${pidfile} 2>&1 &"

stop_cmd="trytond_stop"

trytond_stop()
{
	if [ -e $pidfile ]; then
		echo "Stopping trytond..."
		kill -KILL `cat $pidfile`
	else
		echo "$pidfile not found. Server running?"
		exit 7
	fi
}

load_rc_config $name
run_rc_command "$1"
