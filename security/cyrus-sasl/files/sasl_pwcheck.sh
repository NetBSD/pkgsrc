#!/bin/sh
#
# $NetBSD: sasl_pwcheck.sh,v 1.1 2000/12/13 16:24:51 jlam Exp $
#
# The pwcheck daemon allows UNIX password authentication with Cyrus SASL.
#
# PROVIDE: sasl_pwcheck
# REQUIRE: DAEMON


name="sasl_pwcheck"
command=@PREFIX@/sbin/pwcheck
command_args="& sleep 2"

pid=`ps -ax | awk '{print $1,$5}' | grep ${name} | awk '{print $1}'`

cmd=${1:-start}

case ${cmd} in
start)
	if [ "$pid" = "" -a -x ${command} ]
	then
		echo "Starting ${name}."
		${command} ${command_args}
	fi
	;;

restart)
	( $0 stop )
	sleep 1
	$0 start
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
