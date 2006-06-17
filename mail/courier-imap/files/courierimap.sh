#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courierimap.sh,v 1.13 2006/06/17 19:26:48 jlam Exp $
#
# Courier IMAP services daemon
#
# PROVIDE: courierimap
# REQUIRE: authdaemond
# KEYWORD: shutdown

. /etc/rc.subr

name="courierimap"
rcvar=${name}
command="@PREFIX@/sbin/couriertcpd"
ctl_command="@PREFIX@/sbin/imapd"
pidfile="@VARBASE@/run/imapd.pid"
required_files="@PKG_SYSCONFDIR@/imapd @PKG_SYSCONFDIR@/imapd-ssl"

start_cmd="courierimap_doit start"
stop_cmd="courierimap_doit stop"

courierimap_doit()
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

		. @PKG_SYSCONFDIR@/imapd

		case x$IMAPDSTART in
		x[yY]*)
			@ECHO@ "Starting ${name}."
			${ctl_command} $action
                ;;
		esac
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		${ctl_command} $action
		;;
	esac
}

load_rc_config $name
run_rc_command "$1"
