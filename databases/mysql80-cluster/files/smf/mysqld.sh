#!@RCD_SCRIPTS_SHELL@
#
#	William Pool (Puddle) 01/05
#	SMF Method file for MySQL
#	E-mail: puddle@flipmotion.com
#
# Updated by Joyent for pkgsrc based MySQL installs
#
# NOTE: Make sure DB_DIR is owned BY the mysql user and group and chmod 
# 700.
#

. /lib/svc/share/smf_include.sh

DB_BASE=@LOCALBASE@
DB_EXEC=${DB_BASE}/sbin

DB_DATA=@MYSQL_DATADIR@
PIDFILE=${DB_DATA}/mysql.pid
LOGFILE=@VARBASE@/log/mysql/error.log

CONSTRING=$(svcprop -p mysqld/ndb_connectstring $SMF_FMRI 2>/dev/null)

ulimit -n 10240

case "$1" in
start)
	if [[ "${CONSTRING}" != "none" ]] && [[ "${CONSTRING}" != \"\" ]]; then
		${DB_EXEC}/mysqld --user=mysql \
			--basedir=${DB_BASE} \
			--datadir=${DB_DATA} \
			--pid-file=${PIDFILE} \
			--log-error=${LOGFILE} \
			--ndb-connectstring="${CONSTRING}" \
			> /dev/null &
	else
		${DB_EXEC}/mysqld --user=mysql \
			--basedir=${DB_BASE} \
			--datadir=${DB_DATA} \
			--pid-file=${PIDFILE} \
			--log-error=${LOGFILE} \
			> /dev/null &
	fi
	;;
stop)
	if [ -f ${PIDFILE} ]; then
		/usr/bin/kill `cat ${PIDFILE}` > /dev/null 2>&1
	fi
	;;
restart)
	$0 stop
	while pgrep mysqld > /dev/null
	do
		sleep 1
	done
	$0 start
	;;
*)
	echo ""
	echo "Usage: `basename $0` { start | stop | restart }"
	echo ""
	exit 64
	;;
esac
