#!/bin/sh
#
# $NetBSD: softether_server.sh,v 1.1 2024/03/07 11:48:35 hauke Exp $

# PROVIDE: softether_server
# REQUIRE: DAEMON

. /etc/rc.subr

name="softether_server"
rcvar=$name
command="@PREFIX@/libexec/softether/vpnserver/vpnserver"

start_precmd="softether_server_precmd"
start_cmd="${command} start"
stop_cmd="${command} stop"

softether_server_precmd()
{
        if ! [ -e "@SE_PIDDIR@" ]; then
	        mkdir -p "@SE_PIDDIR@"
	fi
}

load_rc_config $name
run_rc_command "$1"
