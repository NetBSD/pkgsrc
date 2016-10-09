#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: vmtools.sh,v 1.2 2016/10/09 03:41:56 ryoon Exp $
#

# PROVIDE: vmtools
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="vmtools"
rcvar="vmtools"
pidfile="/var/run/vmware-guestd.pid"
command="@PREFIX@/bin/vmtoolsd"
command_args="--background ${pidfile}"

load_rc_config $name
run_rc_command "$1"
