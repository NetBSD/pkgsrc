#! /bin/sh
#
# Courier POP services daemon
#
# PROVIDE: courierpop
# REQUIRE: DAEMON

if [ ! -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="courierpop"
rcvar=${name}
command="/usr/pkg/libexec/courier/couriertcpd"
ctl_command="/usr/pkg/libexec/courier/pop3d.rc"
pidfile="/var/run/pop3d.pid"

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
