#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: salt_master.sh,v 1.3 2017/05/03 08:24:57 sborrill Exp $
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
pidfile="@VARBASE@/run/salt-master.pid"

load_rc_config $name
run_rc_command "$1"
