#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gld.sh,v 1.5 2005/01/19 15:48:41 xtraeme Exp $
#

# PROVIDE: gld
# BEFORE: mail
# REQUIRE: DAEMON LOGIN mysqld

. /etc/rc.subr

name="gld"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/$name.conf"
pidfile="@VARBASE@/run/${name}.pid"
extra_commands="gld_waitmysql_seconds"

: ${gld_waitmysql_seconds:=5}
start_precmd="waitmysql $gld_waitmysql_seconds"

if [ "$1" != "stop" -o "$1" != "status" ]; then
	echo $(check_process $command) > $pidfile
fi

waitmysql()
{
	_sec=$1
	echo "$name: waiting for MySQL ${_sec} seconds..."
	sleep ${_sec}
}

load_rc_config $name
run_rc_command "$1"
