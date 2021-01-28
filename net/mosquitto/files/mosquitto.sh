#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mosquitto.sh,v 1.3 2021/01/28 19:49:29 triaxx Exp $
#
# PROVIDE: mosquitto
# REQUIRE: DAEMON

. /etc/rc.subr

name="mosquitto"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
config="@PKG_SYSCONFDIR@/${name}.conf"

command_args="-d -c $config"

test_cmd="mosquitto_test"
extra_commands=""

load_rc_config $name
run_rc_command "$1"
