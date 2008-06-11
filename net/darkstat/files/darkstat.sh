#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: darkstat.sh,v 1.1 2008/06/11 13:30:06 obache Exp $
#

# PROVIDE: darkstat
# REQUIRE: NETWORKING named

. /etc/rc.subr

name="darkstat"
rcvar=$name
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
