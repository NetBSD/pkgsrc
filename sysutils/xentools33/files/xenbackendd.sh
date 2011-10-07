#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: xenbackendd.sh,v 1.2 2011/10/07 22:37:06 shattered Exp $
#

# PROVIDE: xenbackendd
# REQUIRE: xend

$_rc_subr_loaded . /etc/rc.subr

name="xenbackendd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
