#!/bin/sh
#
# $NetBSD: cupsd.sh,v 1.2 2000/12/09 22:18:24 jlam Exp $
#
# PROVIDE: cupsd
# REQUIRE: DAEMON

name="cupsd"
command=@PREFIX@/sbin/${name}

pid=`ps -ax | awk '{print $1,$5}' | grep ${name} | awk '{print $1}'`

cmd=${1:-start}

case ${cmd} in
start|restart)
	if [ "$pid" = "" -a -x ${command} ]
	then
		echo "Starting ${name}."
		${command}
	else
		echo "Restarting ${name}."
		kill -HUP $pid
	fi
	;;

stop)
	if [ "$pid" != "" ]
	then
		echo "Stopping ${name}."
		kill $pid
	fi
	;;

status)
	if [ "$pid" != "" ]
	then
		echo "${name} is running as pid ${pid}."
	else
		echo "${name} is not running."
	fi
	;;

*)
	echo 1>&2 "Usage: ${name} [restart|start|stop|status]"
	exit 1
	;;
esac
exit 0
