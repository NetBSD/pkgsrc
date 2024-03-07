#!/bin/sh
#
# $NetBSD: softether_client.sh,v 1.1 2024/03/07 11:48:35 hauke Exp $

# PROVIDE: softether_client
# REQUIRE: DAEMON

. /etc/rc.subr

name="softether_client"
rcvar=$name
command="@PREFIX@/libexec/softether/vpnclient/vpnclient"

start_precmd="softether_client_precmd"
start_cmd="${command} start"
stop_cmd="${command} stop"

softether_client_precmd()
{
        if ! [ -e "@SE_PIDDIR@" ]; then
	        mkdir -p "@SE_PIDDIR@"
	fi
}

load_rc_config $name
run_rc_command "$1"
