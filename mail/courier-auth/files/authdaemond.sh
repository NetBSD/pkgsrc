#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: authdaemond.sh,v 1.9 2004/07/15 08:28:33 jlam Exp $
#
# Courier user authentication daemon
#
# PROVIDE: authdaemond
# REQUIRE: LOGIN

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="authdaemond"
rcvar=${name}
command="@PREFIX@/sbin/courierlogger"
ctl_command="@PREFIX@/libexec/courier/authlib/authdaemond"
pidfile="@AUTHDAEMONVAR@/pid"
required_files="@PKG_SYSCONFDIR@/authdaemonrc"

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

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${start_cmd}
fi
