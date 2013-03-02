#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: icinga.sh,v 1.1 2013/03/02 04:08:27 ryoon Exp $
#
# PROVIDE: icinga
# REQUIRE: DAEMON

. /etc/rc.subr

name="icinga"
rcvar=$name
command="@PREFIX@/bin/${name}"
piddir="/var/run/${name}"
pidfile="${piddir}/${name}.lock"
config="@PKG_SYSCONFDIR@/${name}.cfg"

command_args="-d $config"
 
start_precmd="icinga_precmd"
test_cmd="icinga_test"
extra_commands="test reload"

icinga_precmd()
{
    mkdir -p ${piddir}
    chown @ICINGA_USER@ ${piddir}
}

icinga_test()
{
	$command -v $config
}

load_rc_config $name
run_rc_command "$1"
