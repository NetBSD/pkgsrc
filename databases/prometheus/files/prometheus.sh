#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: prometheus.sh,v 1.2 2024/07/25 16:02:56 tnn Exp $
#
# PROVIDE: prometheus
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# Consider installing pkgtools/rc.subr in unprivileged.
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start prometheus:
#
# prometheus=YES

if [ -f @SYSCONFBASE@/rc.subr ]; then
	$_rc_subr_loaded . @SYSCONFBASE@/rc.subr
fi

name="prometheus"
rcvar=$name
prometheus_user="@PROMETHEUS_USER@"
prometheus_group="@PROMETHEUS_GROUP@"
command="@PREFIX@/bin/prometheus"
command_args=">> @LOGDIR@/prometheus.log 2>&1 &"


if [ -f @SYSCONFBASE@/rc.subr -a -d @SYSCONFBASE@/rc.d -a -f @SYSCONFBASE@/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	if [ -f @SYSCONFBASE@/rc.conf ]; then
		. @SYSCONFBASE@/rc.conf
	fi
	case "$1" in
	start)
		if [ -r "${pidfile}" ]; then
			@ECHO@ "Already running ${name}."
		else
			@ECHO@ "Starting ${name}."
			eval ${command} ${command_args}
		fi
		;;
	stop)
		if [ -r "${pidfile}" ]; then
			@ECHO@ "Stopping ${name}."
			kill `@CAT@ "${pidfile}"` && @RM@ "${pidfile}"
		fi
		;;
	*)
		@ECHO@ "Usage: $0 {start|stop}" 1>&2
		exit 10
		;;
	esac
fi
