#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: salt_syndic.sh,v 1.2 2017/05/03 08:24:57 sborrill Exp $
#

# PROVIDE: salt_syndic
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="salt_syndic"
rcvar=$name
command="@PREFIX@/bin/salt-syndic"
command_args="-d"
command_interpreter=@PYTHON@
required_files="@PKG_SYSCONFDIR@/master @PKG_SYSCONFDIR@/minion"
pidfile="@VARBASE@/run/salt-syndic.pid"

load_rc_config $name
run_rc_command "$1"
