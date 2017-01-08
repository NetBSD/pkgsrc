#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: minidlna.sh,v 1.4 2017/01/08 15:42:54 wiz Exp $
#
# PROVIDE: minidlna
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="minidlna"
rcvar=$name
required_files="@PKG_SYSCONFDIR@/minidlna.conf"
pidfile="/var/run/minidlna/minidlna.pid"
command="@PREFIX@/sbin/minidlnad"
command_args=" -f ${required_files}"

load_rc_config ${name}
run_rc_command "$1"
