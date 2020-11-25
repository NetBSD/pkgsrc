#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nats_server.sh,v 1.1 2020/11/25 16:55:46 otis Exp $
#
# PROVIDE: nats_server
# REQUIRE: DAEMON LOGIN mountall network
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start nats-server:
#
# nats_server=YES
#
# The following variables are optional:
#
# nats_server_config="/path/to/nats-server.conf"
#					path to nats-server config file
#					default:
#					@PKG_SYSCONFDIR@/nats-server.conf
# nats_server_pidfile="/path/to/p.pid"	path to nats-server PID file
#					default:
#					@NATS_HOMEDIR@/nats-server.pid
# nats_server_logfile="/path/to/p.log"	path to nats-server log file
#					default:
#					@NATS_LOGFILE@
# nats_server_user="natssrv"		the username for nats-server daemon
# nats_server_group="natssrv"		the group for nats-server daemon

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="nats_server"
rcvar="nats_server"
command="@PREFIX@/bin/nats-server"
: ${nats_server_config:="@PKG_SYSCONFDIR@/nats-server.conf"}
: ${nats_server_pidfile:="@NATS_HOMEDIR@/nats-server.pid"}
: ${nats_server_logfile:="@NATS_LOGFILE@"}
: ${nats_server_user:="natssrv"}
: ${nats_server_group:="natssrv"}

start_cmd="natssrv_start"
stop_cmd="natssrv_stop"

natssrv_start()
{
	@ECHO@ "Starting ${name}."
	ulimit -n 10240
	cd @NATS_HOMEDIR@
	/usr/bin/su ${nats_server_user}:${nats_server_group} \
	   -c "${command} -P ${nats_server_pidfile} \
	   -l ${nats_server_logfile} -c ${nats_server_config} &"
}

natssrv_stop()
{
	local pidfile

	pidfile="${nats_server_pidfile}"
	if [ -r "${pidfile}" ]; then
		echo "Stopping ${name}."
		kill `/bin/cat ${pidfile}`
		/bin/rm "${pidfile}"
	fi
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	pidfile="${nats_server_pidfile}"
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	pidfile="${nats_server_pidfile}"
	case "$1" in
	stop)
		natssrv_stop
		;;
	*)
		eval ${start_cmd}
		;;
	esac
fi
