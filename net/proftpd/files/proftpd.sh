#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: proftpd.sh,v 1.2.32.1 2009/02/09 11:28:55 tron Exp $
#

# PROVIDE: proftpd
# REQUIRE: DAEMON LOGIN network
# KEYWORD: shutdown

. /etc/rc.subr

name="proftpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/proftpd.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
