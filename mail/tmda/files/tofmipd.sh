#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tofmipd.sh,v 1.2 2004/06/10 16:33:40 schmonz Exp $
#

# PROVIDE: mail
# REQUIRE: LOGIN

. /etc/rc.subr

name="tofmipd"
rcvar=$name
command="@PREFIX@/bin/tmda-ofmipd"
command_args="-b"
command_interpreter="@PYTHONBIN@"

load_rc_config $name
run_rc_command "$1"
