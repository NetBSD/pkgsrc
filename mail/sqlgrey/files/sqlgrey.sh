#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sqlgrey.sh,v 1.1.1.1 2007/11/13 16:43:04 ghen Exp $
#
# PROVIDE: sqlgrey
# REQUIRE: DAEMON
# BEFORE: mail

. /etc/rc.subr

name="sqlgrey"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
command_args="-d"
stop_cmd="${command} -k"

load_rc_config $name
run_rc_command "$1"
