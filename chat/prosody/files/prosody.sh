#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: prosody.sh,v 1.6 2022/07/27 01:53:40 khorben Exp $
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
pidfile="@PROSODY_RUN@/${name}.pid"
start_precmd="prosody_precmd"
extra_commands="reload status"

prosody_precmd()
{
    if ! @TEST@ -d @PROSODY_RUN@; then
        @MKDIR@ -m 0755 @PROSODY_RUN@
    fi
    @CHOWN@ @PROSODY_USER@:@PROSODY_GROUP@ @PROSODY_RUN@
    #ulimit -n 2048
}

start_cmd="${ctl_command} start"
stop_cmd="${ctl_command} stop"
reload_cmd="${ctl_command} reload"
status_cmd="${ctl_command} status"

load_rc_config $name
run_rc_command "$1"
