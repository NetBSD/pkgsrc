#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: muc.sh,v 1.3 2007/08/21 15:30:32 abs Exp $
#
# PROVIDE: muc
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="muc"
rcvar=$name
command="@PREFIX@/bin/mu-conference"
required_files="@PKG_SYSCONFDIR@/${name}-jcr.xml"
extra_commands="reload"
muc_user="@JABBERD_USER@"
command_args="-c ${required_files} > /dev/null 2>&1 &"
pidfile="@JABBERD_PIDDIR@/`basename ${command}`.pid"
stop_postcmd="remove_pidfile"
start_precmd="ensure_piddir"

ensure_piddir()
{
	mkdir -p @JABBERD_PIDDIR@
	chown @JABBERD_USER@ @JABBERD_PIDDIR@
}

remove_pidfile()
{
        if [ -f $pidfile ]; then
            rm -f $pidfile
        fi
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${muc_flags} ${command_args}
fi
