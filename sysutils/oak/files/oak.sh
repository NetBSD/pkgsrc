#!@RCD_SCRIPTS_SHELL@
#
# oak - Jason White <jdwhite@jdwhite.org>
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
