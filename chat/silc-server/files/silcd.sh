#!/bin/sh
#
# $NetBSD: silcd.sh,v 1.2 2001/12/17 00:43:11 hubertf Exp $
#
# PROVIDE: silcd
# REQUIRE: DAEMON

. /etc/rc.subr

name="silcd"
pidfile="/var/run/${name}.pid"
command="@PREFIX@/sbin/silcd"
start_precmd="silcd_precmd"
stop_cmd="silcd_stop"
confdir="@SILCD_CONF_DIR@"

silcd_precmd()
{
	if [ -f $confdir/silcd.conf ]; then
		if [ ! -f $confdir/silcd.prv ]; then
			$command -C $confdir
		fi
	else
		warn "Cannot open $confdir/silcd.conf"
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

	if ! eval $_precmd && [ -z "$_rc_force_run" ]; then
		return 1
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

run_rc_command "$1"
