#! /bin/sh
#
# $NetBSD: smokeping.sh,v 1.1.1.1 2003/03/24 15:24:39 bouyer Exp $
#
# PROVIDE: smokeping
# REQUIRE: DAEMON

name="smokeping"
command="@PREFIX@/bin/smokeping"
pidfile="/var/run/${name}.pid"

cmd=${1:-start}

case ${cmd} in
start)
	if [ -x ${command} ]; then
		echo "Starting ${name}."
		${command} > /dev/null 2>&1
	fi
	;;
stop)
	if [ -f ${pidfile} ]; then
		pid=`head -1 ${pidfile}`
		echo "Stopping ${name}."
		kill ${pid}
	fi
	;;
restart)
	$0 stop
	$0 start
	;;
status)
	if [ -f ${pidfile} ]; then
		pid=`head -1 ${pidfile}`
		echo "${name} is running as pid ${pid}."
	else
		echo "${name} is not running."
	fi
	;;
esac
exit 0
