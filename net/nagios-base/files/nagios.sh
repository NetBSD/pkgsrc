#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nagios.sh,v 1.2 2006/05/11 07:32:02 grant Exp $
#
# PROVIDE: nagios
# REQUIRE: DAEMON

. /etc/rc.subr

name="nagios"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}/${name}.lock"
config="@PKG_SYSCONFDIR@/${name}.cfg"

command_args="-d $config"
 
test_cmd="nagios_test"
extra_commands="test"

nagios_test()
{
	$command -v $config
}

load_rc_config $name
run_rc_command "$1"
