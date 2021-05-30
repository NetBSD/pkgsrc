#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: octoprint.sh,v 1.2 2021/05/30 21:53:11 khorben Exp $
#
# Startup script for OctoPrint
#
# PROVIDE: octoprint
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start OctoPrint:
#
# octoprint=YES

$_rc_subr_loaded . /etc/rc.subr

name="octoprint"
rcvar=${name}
command="@PREFIX@/bin/octoprint-@PYVERSSUFFIX@"
pidfile="/tmp/$name.pid"
procname="@PREFIX@/bin/python@PYVERSSUFFIX@"
command_args="daemon start"

load_rc_config $name
run_rc_command "$1"
