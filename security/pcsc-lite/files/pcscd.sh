#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pcscd.sh,v 1.2 2015/01/17 18:43:15 wiz Exp $
#

# PROVIDE: pcscd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="pcscd"
rcvar=$name
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"

