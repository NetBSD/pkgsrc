#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: distccd.sh,v 1.5 2004/11/16 09:24:50 xtraeme Exp $
#

# PROVIDE: distccd
# BEFORE:  DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="distccd"
rcvar="${name}"
command="@PREFIX@/bin/${name}"
pidfile="@DISTCC_PIDDIR@/${name}.pid"
command_args="--daemon --pid-file ${pidfile} --user nobody"

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	case ${1:-start} in
	start)
		if [ -x ${command} ]; then
			echo "Starting ${name}."
			eval ${command} ${distccd_flags} ${command_args}
		fi
		;;
	stop)
		if [ -f ${pidfile} ]; then
			pid=`/bin/head -1 ${pidfile}`
			echo "Stopping ${name}."
			kill -TERM ${pid}
		else
			echo "${name} not running?"
		fi
		;;
	restart)
		( $0 stop )
		sleep 1
		$0 start
		;;
	status)
		if [ -f ${pidfile} ]; then
			pid=`/bin/head -1 ${pidfile}`
			echo "${name} is running as pid ${pid}."
		else
			echo "${name} is not running."
		fi
		;;
		esac
fi
