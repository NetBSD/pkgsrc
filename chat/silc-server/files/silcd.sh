#!/bin/sh
#
# $NetBSD: silcd.sh,v 1.1.1.1 2001/11/30 23:33:35 hubertf Exp $
#
# PROVIDE: silcd
# REQUIRE: DAEMON

name="silcd"
pidfile="/var/run/${name}.pid"

command=${1:-start}

case ${command} in
start)
	if [ ! -f @SILCD_CONF_DIR@/silcd.prv ]
	then
		@PREFIX@/sbin/silcd -C @SILCD_CONF_DIR@
	fi
	if [ -x @PREFIX@/sbin/silcd -a -f @SILCD_CONF_DIR@/silcd.conf ]
	then
		echo "Starting ${name}."
		@PREFIX@/sbin/silcd
	fi
	;;
stop)
	if [ -f ${pidfile} ]; then
		pid=`head -1 ${pidfile}`
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
		pid=`head -1 ${pidfile}`
		echo "${name} is running as pid ${pid}."
	else
		echo "${name} is not running."
	fi
	;;
esac
exit 0
