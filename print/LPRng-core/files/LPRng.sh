#!/bin/sh
#
# $NetBSD: LPRng.sh,v 1.2 2001/01/11 00:31:50 jlam Exp $
#
# PROVIDE: lpd
# REQUIRE: DAEMON

name="lpd"
command=@PREFIX@/sbin/${name}
pidfile="/var/run/${name}.pid"

if [ -f ${pidfile} ]
then
	pid=`head -1 ${pidfile}`
else
	pid=`ps -ax | awk '{print $1,$5}' | grep ${name} | awk '{print $1}'`
fi

cmd=${1:-start}

case ${cmd} in
start)
	if [ "$pid" = "" -a -x ${command} ]
	then
		echo "Starting LPRng."
		${command}
	fi
	;;

stop)
	if [ "$pid" != "" ]
	then
		echo "Stopping LPRng."
		kill $pid
	fi
	;;

restart)
	( $0 stop )
	sleep 5
	$0 start
	;;

status)
	if [ "$pid" != "" ]
	then
		echo "LPRng is running as pid ${pid}."
	else
		echo "LPRng is not running."
	fi
	;;

*)
	echo 1>&2 "Usage: ${name} [restart|start|stop|status]"
	exit 1
	;;
esac
exit 0
