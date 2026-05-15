#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tailscaled.sh,v 1.2 2026/05/15 19:57:33 ktnb Exp $
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

tailscaled_precmd()
{
	if [ ! -d @VARBASE@/run/tailscale ]; then
		@MKDIR@ @VARBASE@/run/tailscale
	fi

	if [ -e ${tailscaled_socket} ]; then
		@RM@ -f ${tailscaled_socket}
	fi
}

tailscaled_start()
{
	${command} &
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
