#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rinetd.sh,v 1.1.1.1 2003/10/01 01:15:44 grant Exp $
#
# PROVIDE: rinetd
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

. /etc/rc.subr

name="rinetd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/rinetd.conf"

load_rc_config $name
run_rc_command "$1"
