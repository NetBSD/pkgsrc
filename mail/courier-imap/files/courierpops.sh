#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courierpops.sh,v 1.7 2004/02/22 03:13:07 jlam Exp $
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

start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
	action=$1
	case ${action} in
	start)	@ECHO@ "Starting ${name}." ;;
	stop)	@ECHO@ "Stopping ${name}." ;;
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
