#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mosquitto.sh,v 1.6 2023/10/06 07:50:54 triaxx Exp $
#
# PROVIDE: mosquitto
# REQUIRE: DAEMON

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="mosquitto"
rcvar=$name
command="@PREFIX@/sbin/${name}"
piddir="@VARBASE@/run/${name}"
pidfile="${piddir}/${name}.pid"
config="@PKG_SYSCONFDIR@/${name}.conf"

command_args="-d -c $config"

start_precmd="mosquitto_precmd"
test_cmd="mosquitto_test"
extra_commands=""

mosquitto_precmd()
{
    mkdir -p ${piddir}
    chown @MOSQUITTO_USER@ ${piddir}
}

load_rc_config $name
run_rc_command "$1"
