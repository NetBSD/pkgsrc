#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: prosody.sh,v 1.7 2025/10/15 10:34:42 sborrill Exp $
#
# PROVIDE: prosody
# REQUIRE: DAEMON

if [ -f @SYSCONFBASE@/rc.subr ]; then
  . @SYSCONFBASE@/rc.subr
fi

name="prosody"
rcvar=${name}
command="@PREFIX@/bin/${name}"
command_args="-D"
command_interpreter="@PREFIX@/bin/lua@LUA_DOT_VERSION@"
required_files="@PKG_SYSCONFDIR@/${name}.cfg.lua"
pidfile="@PROSODY_RUN@/${name}.pid"
start_precmd="prosody_precmd"
stop_postcmd="prosody_postcmd"
extra_commands="reload"
prosody_user="@PROSODY_USER@"
prosody_group="@PROSODY_GROUP@"

prosody_precmd()
{
    if ! @TEST@ -d @PROSODY_RUN@; then
        @MKDIR@ -m 0750 @PROSODY_RUN@
    fi
    @CHOWN@ @PROSODY_USER@:@PROSODY_GROUP@ @PROSODY_RUN@
    #ulimit -n 2048
}

prosody_postcmd()
{
    # Fix for failed socket clean-up which stops
    # prosodyctl working after a restart
    if test -S "@PROSODY_RUN@/${name}.soc"; then
        rm -f "@PROSODY_RUN@/${name}.soc"
    fi
}

load_rc_config $name
run_rc_command "$1"
