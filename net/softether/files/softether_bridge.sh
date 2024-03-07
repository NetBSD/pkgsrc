#!/bin/sh
#
# $NetBSD: softether_bridge.sh,v 1.1 2024/03/07 11:48:35 hauke Exp $

# PROVIDE: softether_bridge
# REQUIRE: DAEMON

. /etc/rc.subr

name="softether_bridge"
rcvar=$name
command="@PREFIX@/libexec/softether/vpnbridge/vpnbridge"

start_precmd="softether_bridge_precmd"
start_cmd="${command} start"
stop_cmd="${command} stop"

softether_bridge_precmd()
{
        if ! [ -e "@SE_PIDDIR@" ]; then
	        mkdir -p "@SE_PIDDIR@"
	fi
}

load_rc_config $name
run_rc_command "$1"
