#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: carbon-relay.sh,v 1.1 2015/12/11 21:40:50 riz Exp $
#
# PROVIDE: carbon-relay
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="carbon_relay"
rcvar=$name
command="@PREFIX@/bin/carbon-relay.py"
config="--config=@PKG_SYSCONFDIR@/carbon.conf"
graphite_user="@GRAPHITE_USER@"
graphite_group="@GRAPHITE_GROUP@"
graphite_dir="@GRAPHITE_DIR@"
extra_commands="status"
start_cmd="${name}_start"
stop_cmd="${name}_stop"
status_cmd="${name}_status"
start_precmd='setproclimits'

setproclimits()
{
	local climit
	climit=$(ulimit -n)
	if [ "$climit" -lt 4096 ]; then
		ulimit -n 4096
	fi
}

carbon_relay_start()
{
	@SU@ -m ${graphite_user} -c "${command} ${config}  start"
}

carbon_relay_stop()
{
	@SU@ -m ${graphite_user} -c "${command} ${config} stop"
}

carbon_relay_status()
{
	@SU@ -m ${graphite_user} -c "${command} ${config} status"
}


if [ -f /etc/rc.subr -a -f /etc/rc.conf ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	case $1 in
	start)
		${start_cmd}
		;;
	stop)
		${stop_cmd}
		;;
	restart)
		${stop_cmd} && ${start_cmd}
		;;
	*)
		@ECHO@ "Usage: $0 {start|stop|restart}" 1>&2
		exit 64
		;;
	esac
fi
