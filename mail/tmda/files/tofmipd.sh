#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tofmipd.sh,v 1.1 2004/06/06 05:08:34 schmonz Exp $
#

# PROVIDE: mail
# REQUIRE: LOGIN

. /etc/rc.subr

name="tofmipd"
rcvar=$name
command="@PREFIX@/bin/tmda-ofmipd"
command_interpreter="@PYTHONBIN@"

load_rc_config $name
run_rc_command "$1"
