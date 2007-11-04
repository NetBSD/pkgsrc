#!@RCD_SCRIPTS_SHELL@
#
# oak - Jason White <jdw-pkgsrc@menelos.com>
#
# PROVIDE: oak
# REQUIRE: DAEMON

. /etc/rc.subr

name="oak"
rcvar=$name
command="@PREFIX@/bin/oak"
command_args="-c @PKG_SYSCONFDIR@/oak.conf"
required_files="@PKG_SYSCONFDIR@/oak.conf"

load_rc_config $name
run_rc_command "$1"
