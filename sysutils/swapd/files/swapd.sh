#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: swapd.sh,v 1.4 2005/02/20 13:56:09 xtraeme Exp $
#
# PROVIDE: swapd
# REQUIRE: DAEMON LOGIN


name="swapd"
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
pidfile="@VARBASE@/run/${name}.pid"
sig_stop="KILL"

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	case ${1:-start} in
	start)
		if [ -x ${command} ]; then
			echo "Starting ${command}."
			eval ${command} ${distccd_flags} ${command_args}
		fi
		;;
	stop)
		if [ -f ${pidfile} ]; then
			pid=`/bin/head -1 ${pidfile}`
			echo "Stopping ${name}."
			kill -${sig_stop} ${pid}
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

if [ "$1" != "stop" -o "$1" != "status" ]; then
	echo $(check_process $command) > $pidfile
fi
