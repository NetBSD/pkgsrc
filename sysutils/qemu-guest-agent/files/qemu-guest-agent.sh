#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qemu-guest-agent.sh,v 1.1 2025/03/16 20:07:39 riastradh Exp $
#
# PROVIDE: qemu_guest_agent
# REQUIRE: DAEMON
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="qemu_guest_agent"
rcvar="${name}"
command="@PREFIX@/bin/qemu-ga"
command_args="-d"


load_rc_config $name
run_rc_command "$1"
