#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smartd.sh,v 1.3 2004/10/20 07:25:39 xtraeme Exp $
#
# PROVIDE: smartd
# REQUIRE: DAEMON

. /etc/rc.subr

name="smartd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
smartd_flags="-p $pidfile"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
