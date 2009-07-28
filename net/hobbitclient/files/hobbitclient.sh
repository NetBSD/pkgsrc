#!/bin/sh
#
#
# PROVIDE: hobbitclient
# REQUIRE: DAEMON

. /etc/rc.subr

name="hobbitclient"
rcvar="$name"
command="@PREFIX@/hobbit/client/runclient.sh"

start_cmd="su - hobbit -c \"$command start\""
restart_cmd="su - hobbit -c \"$command restart\""
stop_cmd="su - hobbit -c \"$command stop\""
status_cmd="su - hobbit -c \"$command status\""

load_rc_config "$name"
run_rc_command "$1"
