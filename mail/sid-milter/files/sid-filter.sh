#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sid-filter.sh,v 1.1 2012/04/04 22:09:49 pettai Exp $
#
# PROVIDE: sidfilter
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="sidfilter"
rcvar=$name
command="@PREFIX@/bin/sid-filter"
pidfile="@VARBASE@/run/sid-filter/${name}.pid"
command_args="-p local:@VARBASE@/run/sid-filter/${name}.sock -P ${pidfile} -l"
start_precmd="sidfilter_precmd"

sidfilter_precmd()
{
        if [ ! -d @VARBASE@/run/sid-filter ]; then
                @MKDIR@ @VARBASE@/run/sid-filter
                @CHMOD@ 0750 @VARBASE@/run/sid-filter
                @CHOWN@ smmsp:smmsp @VARBASE@/run/sid-filter
        fi

        if [ -f @VARBASE@/run/sid-filter/${name}.sock ]; then
                @RM@ -f @VARBASE@/run/sid-filter/${name}.sock
        fi
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${sidfilter_flags} ${command_args}
fi
