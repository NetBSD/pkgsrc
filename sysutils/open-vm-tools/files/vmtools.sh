#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: vmtools.sh,v 1.4 2024/05/10 07:31:46 pho Exp $
#

# PROVIDE: vmtools
# REQUIRE: DAEMON

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="vmtools"
rcvar="vmtools"
pidfile="/var/run/vmware-guestd.pid"
command="@PREFIX@/bin/vmtoolsd"
command_args="--background ${pidfile}"

start_precmd="disable_vmt"
disable_vmt()
{
	# Attempt to detach NetBSD vmt(4) driver so that it won't conflict
	# with vmtoolsd.
	drvctl -d vmt0 >/dev/null 2>&1 || true
}

stop_precmd="enable_vmt"
enable_vmt()
{
	# Attempt to re-attach NetBSD vmt(4) driver.
	drvctl -r -a cpufeaturebus cpu0 >/dev/null 2>&1 || true
}

load_rc_config $name
run_rc_command "$1"
