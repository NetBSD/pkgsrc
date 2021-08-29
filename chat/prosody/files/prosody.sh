#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: prosody.sh,v 1.2 2021/08/29 18:32:29 khorben Exp $
#
# PROVIDE: prosody
# REQUIRE: DAEMON

if [ -f @SYSCONFBASE@/rc.subr ]; then
  . @SYSCONFBASE@/rc.subr
fi

name="prosody"
rcvar=${name}
ctl_command="@PREFIX@/bin/${name}ctl"
required_files="@PKG_SYSCONFDIR@/${name}.cfg.lua"
pidfile="@VARBASE@/run/${name}.pid"
#start_precmd="ulimit -n 2048"
extra_commands="reload status"

start_cmd="${ctl_command} start"
stop_cmd="${ctl_command} stop"
reload_cmd="${ctl_command} reload"
status_cmd="${ctl_command} status"

load_rc_config $name
run_rc_command "$1"
