#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smartd.sh,v 1.5 2022/05/10 07:01:28 triaxx Exp $
#
# PROVIDE: smartd
# REQUIRE: DAEMON

. /etc/rc.subr

name="smartd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_dirs="@VARBASE@/run"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
command_args="-p $pidfile"
extra_commands="reload check"
check_precmd='[ "$rc_pid" ]'
check_cmd='kill -USR1 $rc_pid'

load_rc_config $name
run_rc_command "$1"
