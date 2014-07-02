#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: lwresd.sh,v 1.1.1.1 2014/07/02 02:42:58 jnemeth Exp $
#
# PROVIDE: lwresd
# REQUIRE: SERVERS

. /etc/rc.subr

name="lwresd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/lwresd/${name}.pid"
extra_commands="reload"
start_precmd="lwresd_precmd"

lwresd_precmd()
{
	if [ ! -d @VARBASE@/run/lwresd ]; then
		@MKDIR@ @VARBASE@/run/lwresd
	fi
}

load_rc_config ${name}		# check /etc/rc.conf.d/named9
run_rc_command "$1"
