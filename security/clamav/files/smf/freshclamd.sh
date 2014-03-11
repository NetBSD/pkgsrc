#!@SMF_METHOD_SHELL@
#
# $NetBSD: freshclamd.sh,v 1.1 2014/03/11 14:34:39 jperkin Exp $
#
# Init script for freshclam(1).
#

. /lib/svc/share/smf_include.sh

PIDFILE="@CLAMAV_DBDIR@/freshclamd.pid"

case "$1" in
start)
	@PREFIX@/bin/freshclam -c 2 -d -p ${PIDFILE} -u @CLAMAV_USER@
	;;
stop)
	kill `@HEAD@ -1 ${PIDFILE}`
	;;
refresh)
	kill -HUP `@HEAD@ -1 ${PIDFILE}`
	;;
*)
	echo "Usage: $0 {start|stop|refresh}" >&2
	exit 1
	;;
esac

exit $SMF_EXIT_OK
