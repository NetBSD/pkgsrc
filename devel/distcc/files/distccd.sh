#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: distccd.sh,v 1.7 2005/02/18 07:50:49 xtraeme Exp $
#

# PROVIDE: distccd
# BEFORE:  DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="distccd"
rcvar="${name}"
command="@PREFIX@/bin/${name}"
pidfile="@DISTCC_PIDDIR@/${name}.pid"
command_args="--daemon --pid-file ${pidfile}"
distccd_user="@DISTCC_USER@"
distccd_group="@DISTCC_GROUP@"
start_precmd="distcc_precmd"

distcc_precmd()
{
    if [ ! -d @DISTCC_PIDDIR@ ]; then
	@MKDIR@ @DISTCC_PIDDIR@
	@CHMOD@ 0700 @DISTCC_PIDDIR@
	@CHOWN@ @DISTCC_USER@ @DISTCC_PIDDIR@
    fi
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	case ${1:-start} in
	start)
		distcc_precmd
		if [ -x ${command} ]; then
			echo "Starting ${name}."
			eval ${command} ${distccd_flags} ${command_args}
		fi
		;;
	stop)
		if [ -f ${pidfile} ]; then
			pid=`/bin/head -1 ${pidfile}`
			echo "Stopping ${name}."
			kill -TERM ${pid}
		else
			echo "${name} not running?"
		fi
		;;
	restart)
		( $0 stop )
		sleep 1
		$0 start
		;;
	status)
		if [ -f ${pidfile} ]; then
			pid=`/bin/head -1 ${pidfile}`
			echo "${name} is running as pid ${pid}."
		else
			echo "${name} is not running."
		fi
		;;
		esac
fi
