#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: alertmanager.sh,v 1.1 2026/09/26 10:42:59 tnn Exp $
#
# PROVIDE: alertmanager
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# Consider installing pkgtools/rc.subr in unprivileged.
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start alertmanager:
#
# alertmanager=YES

if [ -f @SYSCONFBASE@/rc.subr ]; then
	$_rc_subr_loaded . @SYSCONFBASE@/rc.subr
fi

name="alertmanager"
rcvar=$name
alertmanager_user="@PROMETHEUS_USER@"
alertmanager_group="@PROMETHEUS_GROUP@"
command="@PREFIX@/bin/alertmanager"
command_args=">> @LOGDIR@/alertmanager.log 2>&1 &"
alertmanager_flags=${alertmanager_flags:-"--config.file=@PKG_SYSCONFDIR@/alertmanager.yml --storage.path=@DATADIR@ --web.listen-address=127.0.0.1:9093 --log.level=error"}

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
