#! /bin/sh
#
# $NetBSD: snmptrapd.sh,v 1.1 2001/08/30 23:31:30 wrstuden Exp $

# PID file:
PF=/var/run/snmptrapd.pid


case $1 in
start)
	if [ -x @PREFIX@/sbin/snmptrapd ]
	then
		echo -n ' snmptrapd'
		@PREFIX@/sbin/snmptrapd -s -l 1 -u ${PF}
	fi
	;;
stop)
	if [ -f ${PF} ]; then
		kill `cat ${PF}`
		rm -f ${PF}
	else
		echo "$0: snmptrapd not running or PID not recorded!" 1>&2
	fi
	;;
restart)
	sh $0 stop
	sh $0 start
	;;
*)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
esac
