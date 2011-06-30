#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: prayer.sh,v 1.3 2011/06/30 01:17:37 schnoebe Exp $
#
# This shell script takes care of starting and stopping prayer,
# a program providing web access to a mail server using IMAP
#

## only for NetBSD
# PROVIDE: prayer
# REQUIRE: LOGIN
# AFTER: mail
# KEYWORD: shutdown
##

PATH=/sbin:/bin:/usr/sbin:/usr/bin:@PREFIX@/sbin
export PATH

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="prayer"
rcvar=$name
command="@PREFIX@/sbin/prayer"
command_args=""
pidfile="@VAR_PREFIX@/pid/prayer.pid"

prayer_flags=${prayer_flags-""} 
OPSYS=@OPSYS@

get_prayer_pid()   
{
	if [ -f ${pidfile} ];  then
		prayer_pid=$(head -1 ${pidfile})
		if kill -0 ${prayer_pid} >/dev/null; then
			:
		else
			prayer_pid=
		fi
	else
		prayer_pid=
	fi

}

prayer_start()
{
	get_prayer_pid

	if [ -n "${prayer_pid}" ]; then
		echo "${command} already running as pid ${prayer_pid}."
		return 1
	fi
	echo "Starting ${name}."
	${command} ${prayer_flags} ${command_args}
}

prayer_stop()
{
	get_prayer_pid

	if [ -z "${prayer_pid}" ]; then
		echo "${command} not running? (check ${pidfile})."
		return 1
	fi
	echo "Stopping ${name}."
	kill -HUP ${prayer_pid}
	prayer_session_pid=$(cat @VAR_PREFIX@/pid/prayer-session.pid)
	if [ -n "${prayer_session_pid}" ]; then
	  if kill -0 ${prayer_session_pid} >/dev/null; then
		kill -HUP ${prayer_session_pid}
	  fi
	fi

	slaves=$(ps -U prayer| awk '/PID/ {next}; {print $1}')
	kill -HUP $slaves

}
prayer_status()
{
	get_prayer_pid

	if [ -z "${prayer_pid}" ]; then
		echo "${command} is not running? (check ${pidfile})."
	else
		echo "${command} is running as pid ${prayer_pid}."
	fi
}

if [ "${OPSYS}" = "NetBSD" ]; then

	stop_cmd=prayer_stop

	load_rc_config $name
	run_rc_command "$1"

else # not NetBSD
	case ${1+"$@"} in
	start)
		prayer_start
		;;
	stop)
		prayer_stop
		;;
	restart)
		prayer_stop
		sleep 2
		prayer_start
		;;
	status)
		prayer_status
		;;
	*)
		echo "Usage: ${0} (start|stop|restart|status)"
		;;
	esac
fi
