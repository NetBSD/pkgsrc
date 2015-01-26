#!@SMF_METHOD_SHELL@
#
# $NetBSD: mysqld.sh,v 1.2 2015/01/26 12:39:56 fhajny Exp $
#
# Init script for mysqld.
#

. /lib/svc/share/smf_include.sh

PIDFILE="@MYSQL_DATADIR@/mysql.pid"

ulimit -n 10240

case "$1" in
start)
	@LOCALBASE@/libexec/mysqld --user=mysql \
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
