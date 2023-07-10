#!@SMF_METHOD_SHELL@
#
# $NetBSD: mariadb.sh,v 1.1 2023/07/10 22:55:50 nia Exp $
#
# Init script for mysqld.
#

. /lib/svc/share/smf_include.sh

PIDFILE="@MARIADB_DATADIR@/mariadb.pid"

ulimit -n 10240

case "$1" in
start)
	if [ ! -d @MARIADB_DATADIR@/mysql ]; then
		@LOCALBASE@/bin/mysql_install_db \
			--datadir=@MARIADB_DATADIR@ \
			--user=@MARIADB_USER@
	fi

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
