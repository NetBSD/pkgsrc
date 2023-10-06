#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mosquitto.sh,v 1.7 2023/10/06 14:21:35 triaxx Exp $
#
# PROVIDE: mosquitto
# REQUIRE: DAEMON

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="mosquitto"
rcvar=$name

load_rc_config $name

: ${mosquitto_user:=@MOSQUITTO_USER@}

command="@PREFIX@/sbin/${name}"
command_args="-d -c @PKG_SYSCONFDIR@/${name}.conf"

piddir="@VARBASE@/run/${name}"
pidfile="${piddir}/${name}.pid"

start_precmd="mosquitto_precmd"
test_cmd="mosquitto_test"
extra_commands=""

mosquitto_precmd()
{
    mkdir -p ${piddir}
    chown ${mosquitto_user} ${piddir}
}

run_rc_command "$1"
