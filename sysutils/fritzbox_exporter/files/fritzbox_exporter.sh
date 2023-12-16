#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: fritzbox_exporter.sh,v 1.1 2023/12/16 22:25:07 wiz Exp $
#
# PROVIDE: fritzbox_exporter
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# Consider installing pkgtools/rc.subr in unprivileged.
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start fritzbox_exporter:
#
# fritzbox_exporter=YES

if [ -f @SYSCONFBASE@/rc.subr ]; then
	$_rc_subr_loaded . @SYSCONFBASE@/rc.subr
fi

name="fritzbox_exporter"
rcvar=$name
fritzbox_exporter_user="@FRITZBOX_EXPORTER_USER@"
fritzbox_exporter_group="@FRITZBOX_EXPORTER_GROUP@"
command="@PREFIX@/bin/fritzbox_exporter"
command_args="> @LOGDIR@/fritzbox_exporter.log 2>&1 &"


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
