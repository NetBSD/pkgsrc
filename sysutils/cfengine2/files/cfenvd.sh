#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cfenvd.sh,v 1.1 2004/08/19 17:13:36 ben Exp $

# PROVIDE: cfenvd
# REQUIRE: cfexecd

. /etc/rc.subr

name="cfenvd"
rcvar=$name
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
