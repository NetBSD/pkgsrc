#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courierpops.sh,v 1.10 2004/07/15 08:29:05 jlam Exp $
#
# Courier POP3/SSL services daemon
#
# PROVIDE: courierpops
# REQUIRE: authdaemond

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="courierpops"
rcvar=${name}
command="@PREFIX@/libexec/courier/couriertcpd"
ctl_command="@PREFIX@/libexec/courier/pop3d-ssl.rc"
pidfile="/var/run/pop3d-ssl.pid"
required_files="@PKG_SYSCONFDIR@/pop3d @PKG_SYSCONFDIR@/pop3d-ssl"
required_files="${required_files} @SSLCERTS@/pop3d.pem"
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

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	exec ${ctl_command} start
fi
