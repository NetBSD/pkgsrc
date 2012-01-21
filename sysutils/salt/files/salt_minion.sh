#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: salt_minion.sh,v 1.1 2012/01/21 20:26:58 apb Exp $
#

# PROVIDE: salt_minion
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="salt_minion"
rcvar=$name
command="@PREFIX@/bin/salt-minion"
command_args="-d"
required_files="@PKG_SYSCONFDIR@/minion"

load_rc_config $name
run_rc_command "$1"
