#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: howl.sh,v 1.1 2005/01/08 06:24:41 schmonz Exp $
#

# PROVIDE: howl
# REQUIRE: NETWORKING

. /etc/rc.subr

name="howl"
rcvar=$name
command="@PREFIX@/bin/mDNSResponder"
stop_cmd=":"
howl_user="howl"

load_rc_config $name
run_rc_command "$1"
