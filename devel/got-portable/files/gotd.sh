#!/bin/sh
#
# $NetBSD: gotd.sh,v 1.1 2024/01/15 19:41:19 vins Exp $
#

# PROVIDE: gotd
# REQUIRE: DAEMON
# KEYWORD: shutdown

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="gotd"
rcvar=$name

: ${gotd_config:="@PKG_SYSCONFDIR@/${name}.conf"}
: ${gotd_server:="@PREFIX@/sbin/${name}"}
: ${gotd_flags:=""}

command="${gotd_server}"
command_args="-f ${gotd_config} -v"
required_files="${gotd_config}"
pidfile="@VARBASE@/run/${name}.pid"

start_precmd="gotd_precmd"
check_cmd="gotd_check"
extra_commands="check"

gotd_check()
{
	echo "Performing sanity check on gotd configuration:"
	eval ${command} ${command_args} ${gotd_flags} -n
}

gotd_precmd()
{
	gotd_check
}

load_rc_config $name
run_rc_command "$1"
