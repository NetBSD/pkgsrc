#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: aiccu.sh,v 1.2 2011/04/24 13:47:45 shattered Exp $
#

# PROVIDE: aiccu
# REQUIRE: NETWORKING

$_rc_subr_loaded . /etc/rc.subr

name="aiccu"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
command_args="start"
stop_command="${command} stop"

load_rc_config $name
run_rc_command "$1"
