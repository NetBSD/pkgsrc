#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courierldapaliasd.sh,v 1.1.1.1 2006/04/28 18:10:21 jlam Exp $
#
# Courier LDAP mail aliasing daemon
#
# PROVIDE: courierldapaliasd
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="courierldapaliasd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="@COURIER_STATEDIR@/tmp/ldapaliasd.pid"
required_files="@PKG_SYSCONFDIR@/ldapaliasrc"

restart_cmd="courier_doit restart"
start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
	action=$1

	case $action in
	restart|start)
		for f in $required_files; do
			if [ ! -r "$f" ]; then
				@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
				return 1
			fi
		done
		case $action in
		restart)	@ECHO@ "Restarting ${name}." ;;
		start)		@ECHO@ "Starting ${name}." ;;
		esac
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		;;
	esac

	${command} $action
}

load_rc_config $name
run_rc_command "$1"
