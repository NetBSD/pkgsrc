#!@SMF_METHOD_SHELL@
#
# $NetBSD: mariadb.sh,v 1.2 2022/04/20 17:36:03 tm Exp $
#
# Init script for mysqld.
#

. /lib/svc/share/smf_include.sh

PIDFILE="@MARIADB_DATADIR@/mariadb.pid"

ulimit -n 10240

case "$1" in
start)
	@LOCALBASE@/sbin/mariadbd --user=@MARIADB_USER@ \
		--basedir=@LOCALBASE@ \
		--datadir=@MARIADB_DATADIR@ \
		--pid-file=${PIDFILE} \
		--log-error=@VARBASE@/log/mariadb/error.log &
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
