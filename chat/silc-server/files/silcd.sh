#!/bin/sh
#
# $NetBSD: silcd.sh,v 1.3 2002/01/26 14:43:17 hubertf Exp $
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
		$command -C $confdir
	fi
}

silcd_stop()
{
	if [ -z "$_pid" ]; then
		if [ -n "$pidfile" ]; then
			echo "${name} not running? (check $pidfile)."
		else
			echo "${name} not running?"
		fi
		exit 1
	fi

	echo "Stopping ${name}."
	_doit=\
"${_user:+su -m $_user -c '}kill -${sig_stop:-TERM} $_pid${_user:+'}"
	eval $_doit

	eval $_pidcmd
	if [ ! $_pid ]; then
		rm -f $pidfile
	fi
}

load_rc_config $name
run_rc_command "$1"
