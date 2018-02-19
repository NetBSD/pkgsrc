#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: threeproxy.sh,v 1.1 2018/02/19 21:25:46 triaxx Exp $
#

# PROVIDE: threeproxy
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="threeproxy"
rcvar=$name
command="@PREFIX@/sbin/3proxy"
command_args="@PKG_SYSCONFDIR@/3proxy/3proxy.cfg"
required_files="@PKG_SYSCONFDIR@/3proxy/3proxy.cfg"

load_rc_config $name
run_rc_command "$1"
