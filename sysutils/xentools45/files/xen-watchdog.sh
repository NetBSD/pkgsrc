#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: xen-watchdog
# REQUIRE: DAEMON
#
# description: Run domain watchdog daemon
#

. /etc/rc.subr

name="xenwatchdog"
rcvar=$name
command="@PREFIX@/sbin/xenwatchdogd"
start_cmd="echo Starting ${name}. && PATH=${PATH}:@PREFIX@/sbin ${command} 30 15"

load_rc_config $name
run_rc_command "$1"
