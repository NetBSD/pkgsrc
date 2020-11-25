#!@SMF_METHOD_SHELL@
#
# $NetBSD: nats-server.sh,v 1.1 2020/11/25 16:55:47 otis Exp $
#
# Init script for nats-server
#

. /lib/svc/share/smf_include.sh

PIDFILE="@NATS_HOMEDIR@/nats-server.pid"
LOGFILE="@NATS_LOGFILE@"
CONFIGFILE="@PKG_SYSCONFDIR@/nats-server.conf"

ulimit -n 10240

case "$1" in
start)
   	@PREFIX@/bin/nats-server -P ${PIDFILE} \
	   -l ${LOGFILE} -c ${CONFIGFILE} &
	;;
stop)
	[ -f ${PIDFILE} ] && kill `@HEAD@ -1 ${PIDFILE}`
	;;
*)
	echo "Usage: $0 {start|stop}" >&2
	exit 1
	;;
esac

exit $SMF_EXIT_OK
