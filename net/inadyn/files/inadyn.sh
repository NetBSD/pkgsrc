#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: inadyn.sh,v 1.2 2015/04/04 07:59:33 snj Exp $
#

# PROVIDE: inadyn
# REQUIRE: NETWORK

. /etc/rc.subr

name="inadyn"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/inadyn.conf"

load_rc_config $name
run_rc_command "$1"
