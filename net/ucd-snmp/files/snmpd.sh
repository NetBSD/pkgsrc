#!/bin/sh
# $NetBSD: snmpd.sh,v 1.6 2002/02/27 15:13:31 tron Exp $

# PID file:
PF=/var/run/snmpd.pid


if [ -f /etc/snmp/snmpd.conf ]
then
    SNMPD_CFG="-c /etc/snmp/snmpd.conf"
fi

case $1 in
start)
	if [ -x @PREFIX@/sbin/snmpd ]
	then
	    echo 'Starting snmpd.'
	    @PREFIX@/sbin/snmpd -s -P ${PF} -A ${SNMPD_CFG}
	fi
	;;
stop)
	if [ -f ${PF} ]; then
		kill `cat ${PF}`
		rm -f ${PF}
	else
		echo "$0: snmpd not running or PID not recorded!" 1>&2
	fi
	;;
restart)
	sh $0 stop
	sleep 5
	sh $0 start
	;;
*)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
esac

