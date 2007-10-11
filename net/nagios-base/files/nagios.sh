#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nagios.sh,v 1.3 2007/10/11 19:24:36 ghen Exp $
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
extra_commands="test reload"

nagios_test()
{
	$command -v $config
}

load_rc_config $name
run_rc_command "$1"
