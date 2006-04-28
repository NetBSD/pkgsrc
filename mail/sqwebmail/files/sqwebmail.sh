#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sqwebmail.sh,v 1.4 2006/04/28 18:16:25 jlam Exp $
#
# Courier SqWebMail services daemon
#
# PROVIDE: sqwebmail
# REQUIRE: authdaemond
# KEYWORD: shutdown

. /etc/rc.subr

name="sqwebmail"
rcvar=${name}
command="@PREFIX@/sbin/courierlogger"
ctl_command="@PREFIX@/sbin/sqwebmaild"
pidfile="@VARBASE@/run/sqwebmaild.pid"
required_files="@PKG_SYSCONFDIR@/calendarmode @PKG_SYSCONFDIR@/sqwebmaild"

start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
	action=$1
	case $action in
	start)
		for f in $required_files; do
			if [ ! -r "$f" ]; then
				@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
				return 1
			fi
		done
		@ECHO@ "Starting ${name}."
		${ctl_command} $action
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		${ctl_command} $action
		;;
	esac
}

load_rc_config $name
run_rc_command "$1"
