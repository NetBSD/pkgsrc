#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: kea.sh,v 1.1 2022/12/19 07:44:50 sekiya Exp $
#
# PROVIDE: kea
# REQUIRE: DAEMON
# BEFORE: LOGIN
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start Kea:
#
# kea=YES

name="kea"

if [ -f @SYSCONFBASE@/rc.subr ]; then
	. @SYSCONFBASE@/rc.subr

	rcvar=$name
	command="@PREFIX@/sbin/keactrl"
	command_args="start"
	required_files="@PKG_SYSCONFDIR@/keactrl.conf"
	extra_commands="reload"
	stop_cmd="@PREFIX@/sbin/keactrl stop"
	reload_cmd="@PREFIX@/sbin/keactrl reload"

	load_rc_config $name
	run_rc_command "$1"
else
	ctl_command="@PREFIX@/sbin/keactrl"

	if [ ! -x ${ctl_command} ]; then
		return
	fi

	case "$1" in
	start)
		@ECHO@ "Starting ${name}."
		${ctl_command} start
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		${ctl_command} stop
		;;
	reload)
		${ctl_command} reload
		;;
	restart)
		"$0" stop
		sleep 10
		"$0" start
		;;
	*)
		${ctl_command} "$1"
		;;
	esac
fi
