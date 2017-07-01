#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: radicale.sh,v 1.1 2017/07/01 05:57:07 darcy Exp $
#
# PROVIDE: radicale
# REQUIRE: DAEMON
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="radicale"
rcvar=$name
radicale_user=@RADICALE_USER@
radicale_group=@RADICALE_GROUP@
command="@PREFIX@/bin/radicale"
command_interpreter="@PYTHONBIN@"
required_files="@PKG_SYSCONFDIR@/radicale/config"

load_rc_config $name
run_rc_command "$1"
