#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: howl.sh,v 1.2 2006/01/01 18:27:53 tron Exp $
#

# PROVIDE: howl
# REQUIRE: NETWORKING

. /etc/rc.subr

name="howl"
rcvar=$name
command="@PREFIX@/bin/mDNSResponder"
howl_user="@HOWL_USER@"
sig_stop=KILL

load_rc_config $name
run_rc_command "$1"
