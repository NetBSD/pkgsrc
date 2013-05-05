#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: salt_master.sh,v 1.2 2013/05/05 12:26:23 imil Exp $
#

# PROVIDE: salt_master
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="salt_master"
rcvar=$name
command="@PREFIX@/bin/salt-master"
command_args="-d"
command_interpreter=@PYTHON@
required_files="@PKG_SYSCONFDIR@/master"

load_rc_config $name
run_rc_command "$1"
