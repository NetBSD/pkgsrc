#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: socks5.sh,v 1.1 2002/10/02 13:27:14 grant Exp $
#
# PROVIDE: socks5
# REQUIRE: DAEMON

. /etc/rc.subr

name="socks5"
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/socks5.conf"

load_rc_config $name
run_rc_command "$1"
