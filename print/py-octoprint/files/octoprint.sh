#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: octoprint.sh,v 1.3 2021/08/29 20:00:43 khorben Exp $
#
# Startup script for OctoPrint
#
# PROVIDE: octoprint
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start OctoPrint:
#
# octoprint=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="octoprint"
rcvar=${name}
command="@PREFIX@/bin/octoprint-@PYVERSSUFFIX@"
pidfile="/tmp/$name.pid"
procname="@PREFIX@/bin/python@PYVERSSUFFIX@"
command_args="daemon start"

load_rc_config $name
run_rc_command "$1"
