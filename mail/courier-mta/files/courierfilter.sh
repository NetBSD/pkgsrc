#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courierfilter.sh,v 1.1.1.1 2006/04/28 18:10:21 jlam Exp $
#
# Courier mail filter daemon
#
# PROVIDE: courierfilter
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="courierfilter"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"

restart_cmd="courier_doit restart"
start_precmd="courierfilter_prestart"
start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
	action=$1

	case $action in
	restart)	@ECHO@ "Restarting ${name}." ;;
	start)		@ECHO@ "Starting ${name}." ;;
	stop)		@ECHO@ "Stopping ${name}." ;;
	esac

	${command} $action
}

load_rc_config $name
run_rc_command "$1"
