#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: minidlna.sh,v 1.3 2015/01/15 20:53:18 degroote Exp $
#
# PROVIDE: minidlna
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="minidlna"
required_files="@PKG_SYSCONFDIR@/minidlna.conf"
pidfile="/var/run/minidlna/minidlna.pid"
command="@PREFIX@/sbin/minidlnad"
command_args=" -f ${required_files}"

load_rc_config ${name}
run_rc_command "$1"
