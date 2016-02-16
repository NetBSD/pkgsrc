#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: salt_syndic.sh,v 1.1 2016/02/16 00:00:08 khorben Exp $
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

load_rc_config $name
run_rc_command "$1"
