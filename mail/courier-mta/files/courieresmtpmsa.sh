#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courieresmtpmsa.sh,v 1.1.1.1 2006/04/28 18:10:21 jlam Exp $
#
# Courier ESMTP-MSA (RFC 2476) services daemon
#
# PROVIDE: courieresmtpmsa
# REQUIRE: authdaemond courierd
# KEYWORD: shutdown

. /etc/rc.subr

name="courieresmtpmsa"
rcvar=${name}
command="@PREFIX@/sbin/couriertcpd"
ctl_command="@PREFIX@/sbin/esmtpd-msa"
pidfile="@VARBASE@/run/esmtpd-msa.pid"
required_files="@PKG_SYSCONFDIR@/esmtpd @PKG_SYSCONFDIR@/esmtpd-msa"

start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
	action=$1
	case ${action} in
	start)
		for f in $required_files; do
			if [ ! -r "$f" ]; then
				@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
				return 1
			fi
		done

		. @PKG_SYSCONFDIR@/esmtpd
		. @PKG_SYSCONFDIR@/esmtpd-msa

		case x$ESMTPDSTART in
		x[yY]*)
			@ECHO@ "Starting ${name}."
			@TEST@ -f @PKG_SYSCONFDIR@/esmtpacceptmailfor.dat ||
				@PREFIX@/sbin/makeacceptmailfor
			@TEST@ -f @PKG_SYSCONFDIR@/${ACCESSFILE}.dat ||
				@PREFIX@/sbin/makesmtpaccess-msa
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
