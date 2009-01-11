#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: proftpd.sh,v 1.3 2009/01/11 22:47:54 shattered Exp $
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
