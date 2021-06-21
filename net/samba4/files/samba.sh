#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: samba.sh,v 1.2 2021/06/21 10:23:48 nia Exp $
#
# PROVIDE: samba
# REQUIRE: DAEMON

. /etc/rc.subr

name="samba"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@SMB_PID@/${name}.pid"
required_files="@SMB_CONFIG@/smb.conf"
extra_commands="reload"
start_precmd="samba_precmd"

samba_precmd()
{
	if ! [ -f /proc/cpuinfo ]; then
		echo "WARNING: Samba requires a Linux-compatible procfs!"
		echo "WARNING: Please mount /proc before starting Samba."
	fi
}

load_rc_config $name
run_rc_command "$1"
