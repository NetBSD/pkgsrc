#!@RCD_SCRIPTS_SHELL@
#
#
# $NetBSD: jftpgw.sh,v 1.1.1.1 2004/02/23 01:32:34 xtraeme Exp $
#
# PROVIDE: jftpgw
# REQUIRE: DAEMON LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

name="jftpgw"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
