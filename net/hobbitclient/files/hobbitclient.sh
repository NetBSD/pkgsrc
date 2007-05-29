#!/bin/sh
#
#
# PROVIDE: hobbitclient
# REQUIRE: DAEMON

. /etc/rc.subr

name="hobbitclient"
rcvar="$name"
command="@PREFIX@/hobbit/client/runclient.sh"

start_cmd="$command start"
restart_cmd="$command restart"
stop_cmd="$command stop"
status_cmd="$command status"

load_rc_config "$name"
run_rc_command "$1"
