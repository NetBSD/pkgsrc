#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: snmp_exporter.sh,v 1.1 2023/12/29 20:55:44 wiz Exp $
#
# PROVIDE: snmp_exporter
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# Consider installing pkgtools/rc.subr in unprivileged.
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start snmp_exporter:
#
# snmp_exporter=YES

if [ -f @SYSCONFBASE@/rc.subr ]; then
	$_rc_subr_loaded . @SYSCONFBASE@/rc.subr
fi

name="snmp_exporter"
rcvar=$name
snmp_exporter_user="@SNMP_EXPORTER_USER@"
snmp_exporter_group="@SNMP_EXPORTER_GROUP@"
command="@PREFIX@/bin/snmp_exporter"
command_args="--config.file @PKG_SYSCONFDIR@/snmp.yml > @LOGDIR@/snmp_exporter.log 2>&1 &"


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
