#! /bin/sh
#
# Courier IMAP/SSL services daemon
#
# PROVIDE: courierimaps
# REQUIRE: DAEMON

if [ ! -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="courierimaps"
rcvar=${name}
command="/usr/pkg/libexec/courier/couriertcpd"
ctl_command="/usr/pkg/libexec/courier/imapd-ssl.rc"
pidfile="/var/run/imapd-ssl.pid"

start_cmd="courier_doit start"
stop_cmd="courier_doit stop"

courier_doit()
{
	action=$1
	case ${action} in
	start)		echo "Starting ${rcvar}." ;;
	stop)		echo "Stopping ${rcvar}." ;;
	esac

	${ctl_command} ${action}
}

if [ ! -d /etc/rc.d ]
then
	echo -n " ${name}"
	exec ${ctl_command} start
fi

load_rc_config $name
run_rc_command "$1"
