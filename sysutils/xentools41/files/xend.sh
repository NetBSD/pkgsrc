#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: xend
# REQUIRE: xencommons

. /etc/rc.subr

name="xend"
rcvar=$name
command="@PREFIX@/sbin/xend"
command_interpreter="@RCD_INTERPRETER@"
start_cmd="echo Starting ${name}. && PATH=${PATH}:@PREFIX@/sbin ${command} start"
pidfile="/var/run/xend.pid"

load_rc_config $name
run_rc_command "$1"
