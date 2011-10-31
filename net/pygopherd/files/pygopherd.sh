#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pygopherd.sh,v 1.2 2011/10/31 08:45:08 obache Exp $
#
# PROVIDE: pygopherd
# REQUIRE: DAEMON
#
# To start spread at startup, copy this script to /etc/rc.d and set
# spread=YES in /etc/rc.conf.
#
# Addtionally you may set spread_log to a file where to log stuff.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcd_dir=`@DIRNAME@ $0`

name="pygopherd"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_interpreter="@PYTHONBIN@"
pidfile="@VARBASE@/run/${name}.pid"
conf_file="@PKG_SYSCONFDIR@/${name}.conf"
mime_file="@PKG_SYSCONFDIR@/mime.types"
required_files="${conf_file} ${mime_file}"

start_precmd="${name}_precmd"

pygopherd_precmd()
{
        if [ ! -d @RUNTIMEDIR@ ]
        then
                @MKDIR@ @RUNTIMEDIR@
                @CHMOD@ 0750 @RUNTIMEDIR@
                @CHOWN@ @PKG_USERS@ @RUNTIMEDIR@
        fi
}

load_rc_config $name
run_rc_command "$1"
