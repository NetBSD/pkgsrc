#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: knot.sh,v 1.3 2015/10/26 19:23:08 pettai Exp $
#
# PROVIDE: knot
# REQUIRE: NETWORKING syslogd
# BEFORE:  DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="knot"
rcvar=${name}
command="@PREFIX@/sbin/knotc"
knotd="@PREFIX@/sbin/knotd"
command_args=""
pidfile="@VARBASE@/knot/${name}.pid"
start_precmd="knot_precmd"
extra_commands="reload"
start_cmd="$knotd -d"
stop_cmd="$command stop"
reload_cmd="$command reload"
status_cmd="$command status"

knot_precmd()
{
        if [ ! -d @VARBASE@/run/knot ]; then
                @MKDIR@ @VARBASE@/run/knot
                @CHMOD@ 0750 @VARBASE@/run/knot
                @CHOWN@ root:wheel @VARBASE@/run/knot
        fi
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${knot_flags} ${command_args}
fi
