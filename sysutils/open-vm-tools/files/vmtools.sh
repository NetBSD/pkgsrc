#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: vmtools.sh,v 1.3 2023/02/17 21:58:09 khorben Exp $
#

# PROVIDE: vmtools
# REQUIRE: DAEMON

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="vmtools"
rcvar="vmtools"
pidfile="/var/run/vmware-guestd.pid"
command="@PREFIX@/bin/vmtoolsd"
command_args="--background ${pidfile}"

load_rc_config $name
run_rc_command "$1"
