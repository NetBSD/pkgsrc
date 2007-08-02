#!/bin/sh
#
# $NetBSD: denyhosts.sh,v 1.1.1.1 2007/08/02 17:27:30 he Exp $
#
# PROVIDE: denyhosts
# REQUIRE: DAEMON
#
# You will need to set some variables in /etc/rc.conf to start denyhosts:
#
# denyhosts=YES

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="denyhosts"
rcvar=$name
command=@PREFIX@/bin/denyhosts.py
command_interpreter=@PYTHONBIN@
command_args="--config @PKG_SYSCONFDIR@/denyhosts.conf --daemon"
pidfile=@VARBASE@/run/denyhosts.pid
required_files=@PKG_SYSCONFDIR@/denyhosts.conf

if [ ! -f /etc/hosts.deny ]; then
	touch /etc/hosts.deny
fi

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	exec ${command} ${command_args}
fi
