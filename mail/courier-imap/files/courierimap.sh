#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courierimap.sh,v 1.11 2005/02/18 22:12:46 jlam Exp $
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
required_vars="authdaemond"

start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
	action=$1
	case ${action} in
	start)
		for _f in $required_vars; do
			eval _value=\$${_f}
			case $_value in
			[Yy][Ee][Ss]|[Tt][Rr][Uu][Ee]|[Oo][Nn]|1)
				;;
			*)
				@ECHO@ 1>&2 "$0: WARNING: \$${_f} is not set"
				if [ -z $rc_force ]; then
					return 1
				fi
				;;
			esac
		done
		for f in $required_files; do
			if [ ! -r "$f" ]; then
				@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
				if [ -z $rc_force ]; then
					return 1
				fi
			fi
		done
		@ECHO@ "Starting ${name}."
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		;;
	esac

	${ctl_command} ${action}
}

load_rc_config $name
run_rc_command "$1"
