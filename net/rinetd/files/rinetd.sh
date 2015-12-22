#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rinetd.sh,v 1.2 2015/12/22 10:09:15 sborrill Exp $
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
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
