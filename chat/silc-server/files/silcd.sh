#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: silcd.sh,v 1.7 2003/10/16 12:37:44 salo Exp $
#
# PROVIDE: silcd
# REQUIRE: DAEMON
#
# To start silcd at startup, copy this script to /etc/rc.d and set
# silcd=YES in /etc/rc.conf.

. /etc/rc.subr

name="silcd"
rcvar=$name
confdir="@PKG_SYSCONFDIR@"
required_files="$confdir/silcd.conf"
required_dirs="/var/log/silcd"
pidfile="/var/run/${name}.pid"
command="@PREFIX@/sbin/silcd"
start_precmd="silcd_precmd"
stop_cmd="silcd_stop"

silcd_precmd()
{
	if [ ! -f $confdir/silcd.prv ]; then
		umask 7177 && $command -C $confdir
	fi
}

silcd_stop()
{
	# Backward compat with NetBSD <1.6:
	[ -z "$rc_pid" ] && rc_pid=$_pid
	[ -z "$rc_pidcmd" ] && rc_pidcmd=$_pidcmd

	if [ -z "$rc_pid" ]; then
		if [ -n "$pidfile" ]; then
			echo "${name} not running? (check $pidfile)."
		else
			echo "${name} not running?"
		fi
		exit 1
	fi

	echo "Stopping ${name}."
	_doit=\
"${_user:+su -m $_user -c '}kill -${sig_stop:-TERM} $rc_pid${_user:+'}"
	eval $_doit

	eval $rc_pidcmd
	if [ ! $rc_pid ]; then
		rm -f $pidfile
	fi
}

load_rc_config $name
run_rc_command "$1"
