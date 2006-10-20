#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mtdaapd.sh,v 1.1.1.1 2006/10/20 20:28:28 adrianp Exp $
#

# PROVIDE: mtdaapd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="mtdaapd"
rcvar=$name
command="@PREFIX@/sbin/mt-daapd"
required_files="@PKG_SYSCONFDIR@/mt-daapd.conf"
command_args="</dev/null >/dev/null 2>&1 &"

load_rc_config $name
run_rc_command "$1"
