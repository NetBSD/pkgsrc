#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nagios.sh,v 1.5 2008/06/09 12:36:15 gdt Exp $
#
# PROVIDE: nagios
# REQUIRE: DAEMON

. /etc/rc.subr

name="nagios"
rcvar=$name
command="@PREFIX@/bin/${name}"
piddir="/var/run/${name}"
pidfile="${piddir}/${name}.lock"
config="@PKG_SYSCONFDIR@/${name}.cfg"

command_args="-d $config"
 
start_precmd="nagios_precmd"
test_cmd="nagios_test"
extra_commands="test reload"

nagios_precmd()
{
    mkdir -p ${piddir}
    chown nagios ${piddir}
}

nagios_test()
{
	$command -v $config
}

load_rc_config $name
run_rc_command "$1"
