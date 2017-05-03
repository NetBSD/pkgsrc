#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: salt_minion.sh,v 1.3 2017/05/03 08:24:57 sborrill Exp $
#

# PROVIDE: salt_minion
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="salt_minion"
rcvar=$name
command="@PREFIX@/bin/salt-minion"
command_args="-d"
command_interpreter=@PYTHON@
required_files="@PKG_SYSCONFDIR@/minion"
pidfile="@VARBASE@/run/salt-minion.pid"

load_rc_config $name
run_rc_command "$1"
