#!/bin/sh
#
# $NetBSD: adsl.sh,v 1.2 2002/07/18 00:10:07 abs Exp $
#
# PROVIDE: adsl
# REQUIRE: ipnat
#
# On systems with rc.d you will need to copy this to /etc/rc.d and set
# 'adsl=YES' in /etc/rc.conf

adsl_start()
{
	echo "Starting speedtouch adsl."
	# Ensure we have at least tun0 - NetBSD 1.6 and later
	ifconfig tun0 2>/dev/null || ifconfig tun0 create
	@PREFIX@/sbin/modem_run -f @PREFIX@/libdata/alcaudsl.sys -m
	@PREFIX@/sbin/ppp -ddial adsl
}

adsl_stop()
{
	PID=`ps ax | awk '/ppp -ddial adsl $/{print $1}'`
	if [ -n "$PID" ]; then
	    echo "Stopping speedtouch adsl."
	    kill $PID
	fi
}

if [ ! -d /etc/rc.d ]
then
	case "$1" in
	    start)	adsl_start		;;
	    stop)	adsl_stop		;;
	    rstart)	adsl_stop ; adsl_start	;;
	esac
	exit
fi

. /etc/rc.subr

name="adsl"
rcvar=$name
start_cmd="adsl_start"
stop_cmd="adsl_stop"

load_rc_config $name
run_rc_command "$1"
