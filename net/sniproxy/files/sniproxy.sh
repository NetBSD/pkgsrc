#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sniproxy.sh,v 1.1 2019/01/11 23:09:53 schmonz Exp $

# PROVIDE: sniproxy
# REQUIRE: NETWORKING

. /etc/rc.subr

name="sniproxy"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/sniproxy.conf"
pidfile="@VARBASE@/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
