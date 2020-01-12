#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nsca-ng-server.sh,v 1.1 2020/01/12 21:53:22 maya Exp $
#
# PROVIDE: nsca_ng_server
# REQUIRE: DAEMON

. /etc/rc.subr

name="nsca_ng_server"
rcvar=$name
command="@PREFIX@/sbin/nsca-ng"
required_files="@PKG_SYSCONFDIR@/nsca-ng.cfg"

load_rc_config $name
run_rc_command "$1"
