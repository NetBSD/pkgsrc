#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: inadyn.sh,v 1.1 2011/12/14 13:35:47 abs Exp $
#

# PROVIDE: inadyn
# REQUIRE: NETWORK

. /etc/rc.subr

name="inadyn"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/inadyn.conf"

load_rc_config $name
run_rc_command "$1"
