#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: salt_minion.sh,v 1.2 2013/05/05 12:26:23 imil Exp $
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

load_rc_config $name
run_rc_command "$1"
