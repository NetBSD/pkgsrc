#!/bin/sh
#
# $NetBSD: dhid.sh,v 1.2 2000/08/09 21:00:10 hubertf Exp $

DHID=@PREFIX@/sbin/dhid

case "$1" in
start)
	if [ ! -f "@PREFIX@/etc/dhid.conf" ]; then
		pkg_info -D dhid
		echo "@PREFIX@/etc/dhid.conf not found, exiting."
		exit 1
	fi
	if [ -f ${DHID} ]; then
		@ECHO@ -n " dhid"
		${DHID}
	fi
	;;
stop)
	if [ -f /var/run/dhid.pid ]; then
		kill `cat /var/run/dhid.pid`
		rm -f /var/run/dhid.pid
	fi
	;;
*)
	echo "Usage: $0 {start,stop}"
	exit 1
	;;
esac
