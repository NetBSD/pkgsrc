#!/bin/sh
#
# $NetBSD: isakmpd.sh,v 1.1 2002/04/04 09:42:30 martti Exp $
#

case "$1" in
	start)
		if [ -r /etc/isakmpd/isakmpd.conf ]; then
			echo 'Starting isakmpd'
			@PREFIX@/sbin/isakmpd
		fi
		;;
	stop)
		if [ -f /var/run/isakmpd.pid ]; then
			echo 'Stopping isakmpd'
			kill `cat /var/run/isakmpd.pid`
			rm -f /var/run/isakmpd.pid
		fi
		;;
	*)
		echo "$0 start | stop"
		;;
esac
