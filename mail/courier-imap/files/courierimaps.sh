#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courierimaps.sh,v 1.6 2002/09/20 02:01:56 grant Exp $
#
# Courier IMAP/SSL services daemon
#
# PROVIDE: courierimaps
# REQUIRE: authdaemond

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="courierimaps"
rcvar=${name}
command="@PREFIX@/libexec/courier/couriertcpd"
ctl_command="@PREFIX@/libexec/courier/imapd-ssl.rc"
pidfile="/var/run/imapd-ssl.pid"
required_files="@PKG_SYSCONFDIR@/imapd @PKG_SYSCONFDIR@/imapd-ssl"
required_files="${required_files} @SSLCERTS@/imapd.pem"

start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
	action=$1
	case ${action} in
	start)	echo "Starting ${name}." ;;
	stop)	echo "Stopping ${name}." ;;
	esac

	${ctl_command} ${action}
}

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${start_cmd}
fi
