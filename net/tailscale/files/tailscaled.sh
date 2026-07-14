#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tailscaled.sh,v 1.3 2026/07/14 20:43:31 schmonz Exp $
#
# PROVIDE: tailscaled
# REQUIRE: DAEMON
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start tailscaled
#
# tailscaled=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="tailscaled"
rcvar=${name}
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/tailscale/${name}.pid"
start_precmd="tailscaled_precmd"
start_cmd="tailscaled_start"
start_postcmd="tailscaled_poststart"
tailscaled_socket="@VARBASE@/run/tailscale/${name}.sock"
tailscaled_statedir="@VARBASE@/db/tailscale"
tailscaled_logfile="@VARBASE@/log/tailscale"

tailscaled_precmd()
{
	if [ ! -d @VARBASE@/run/tailscale ]; then
		@MKDIR@ @VARBASE@/run/tailscale
	fi

	if [ ! -d @VARBASE@/log ]; then
		@MKDIR@ @VARBASE@/log
	fi

	if [ -e ${tailscaled_socket} ]; then
		@RM@ -f ${tailscaled_socket}
	fi
}

tailscaled_start()
{
	${command} --statedir=${tailscaled_statedir} --socket=${tailscaled_socket} >>${tailscaled_logfile} 2>&1 &
}

tailscaled_poststart() {
	echo $! > ${pidfile}
}

tailscaled_stop()
{
	kill -HUP $(check_pidfile $pidfile $name)
}

load_rc_config $name
run_rc_command "$1"
