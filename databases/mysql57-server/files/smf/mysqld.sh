#!@SMF_METHOD_SHELL@
#
# $NetBSD: mysqld.sh,v 1.1 2016/09/16 06:49:12 adam Exp $
#
# Init script for mysqld.
#

. /lib/svc/share/smf_include.sh

PIDFILE="@MYSQL_DATADIR@/mysql.pid"

ulimit -n 10240

case "$1" in
start)
	@LOCALBASE@/sbin/mysqld --user=mysql \
		--basedir=@LOCALBASE@ \
		--datadir=@MYSQL_DATADIR@ \
		--pid-file=${PIDFILE} \
		--log-error=@VARBASE@/log/mysql/error.log &
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
