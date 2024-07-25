#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mimir.sh,v 1.1 2024/07/25 16:58:13 tnn Exp $
#
# PROVIDE: mimir
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# Consider installing pkgtools/rc.subr in unprivileged.
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start mimir:
#
# mimir=YES

if [ -f @SYSCONFBASE@/rc.subr ]; then
	$_rc_subr_loaded . @SYSCONFBASE@/rc.subr
fi

name="mimir"
rcvar=$name
mimir_chdir="@DATADIR@"
mimir_user="@MIMIR_USER@"
mimir_group="@MIMIR_GROUP@"
command="@PREFIX@/bin/mimir"
command_args="--config.file=@PKG_SYSCONFDIR@/mimir.yaml >> @LOGDIR@/mimir.log 2>&1 &"

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
