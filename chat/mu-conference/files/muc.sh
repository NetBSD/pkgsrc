#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: muc.sh,v 1.1.1.1 2004/06/26 14:28:09 abs Exp $
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
command_args="-c ${required_files} 2>&1 > /dev/null &"
pidfile="@JABBERD_PIDDIR@/${name}.pid"
stop_postcmd="remove_pidfile"
start_precmd="ensure_piddir"

ensure_piddir()
{
	mkdir -p @JABBERD_PIDDIR@
	chown @JABBERD_USER@ @JABBERD_PIDDIR@
}

remove_pidfile()
{
        if [ -f @JABBERD_PIDDIR@/${name}.pid ]; then
            rm -f @JABBERD_PIDDIR@/${name}.pid
        fi
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${muc_flags} ${command_args}
fi
