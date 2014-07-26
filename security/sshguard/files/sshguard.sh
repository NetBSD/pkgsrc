#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sshguard.sh,v 1.1 2014/07/26 19:57:44 tron Exp $
#
# PROVIDE: sshguard
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name=sshguard
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
sshguard_flags="-f 100:@VARBASE@/run/sshd.pid -l /var/log/authlog"
command_args="-i $pidfile"
start_cmd=sshguard_start

sshguard_start()
{
	@ECHO@ "Starting ${name}."
	nohup ${command} ${sshguard_flags} ${command_args} </dev/null >/dev/null 2>&1 &
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	case ${1:-start} in
	start)
		sshguard_start
		;;
	stop)
		if [ -f ${pidfile} ]; then
			pid=`@HEAD@ -1 ${pidfile}`
			@ECHO@ "Stopping ${name}."
			kill -TERM ${pid}
		else
			@ECHO@ "${name} not running?"
		fi
		;;
	restart)
		$0 stop
		sleep 1
		$0 start
		;;
	status)
		if [ -f ${pidfile} ]; then
			pid=`@HEAD@ -1 ${pidfile}`
			@ECHO@ "${name} is running as pid ${pid}."
		else
			@ECHO@ "${name} is not running."
		fi
		;;
	esac
fi
