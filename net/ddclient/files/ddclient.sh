#!/bin/sh
#
# $NetBSD: ddclient.sh,v 1.2 2001/12/09 21:44:52 jlam Exp $
#
# Dynamic DNS update client
#
# PROVIDE: ddclient
# REQUIRE: DAEMON

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="ddclient"
rcvar=${name}
command="@PERL5@"
daemon="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="${daemon} @PKG_SYSCONFDIR@/${name}.conf"
start_cmd="ddclient_start"
extra_commands="reload"

ddclient_start()
{
	@ECHO@ "Starting ${name}."
	${daemon} ${ddclient_flags} ${command_args}
}

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${daemon} ${ddclient_flags} ${command_args}
fi
