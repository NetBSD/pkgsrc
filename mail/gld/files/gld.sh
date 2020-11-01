#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gld.sh,v 1.6 2020/11/01 14:21:44 spz Exp $
#

# PROVIDE: gld
# BEFORE: mail
# REQUIRE: DAEMON LOGIN @GLDDB@

. /etc/rc.subr

name="gld"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/$name.conf"
pidfile="@VARBASE@/run/${name}.pid"
extra_commands="gld_waitdb_seconds"

: ${gld_waitmysql_seconds:=5}
: ${gld_waitdb_seconds:=$gld_waitmysql_seconds}
start_precmd="waitdb $gld_waitdb_seconds"

if [ "$1" != "stop" -o "$1" != "status" ]; then
	echo $(check_process $command) > $pidfile
fi

waitdb()
{
	_sec=$1
	echo "$name: waiting for @GLDDB@ ${_sec} seconds..."
	sleep ${_sec}
}

load_rc_config $name
run_rc_command "$1"
