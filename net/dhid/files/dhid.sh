#!/bin/sh
#
# $NetBSD: dhid.sh,v 1.3 2000/09/20 05:14:11 jlam Exp $
#
# PROVIDE: dhid
# REQUIRE: NETWORK

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
