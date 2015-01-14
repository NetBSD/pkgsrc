#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: minidlna.sh,v 1.2 2015/01/14 21:32:20 degroote Exp $
#
# PROVIDE: minidlna
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="minidlna"
rcvar=${name}
start_cmd="start_minidlna"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
pidfile="/var/run/minidlna/minidlna.pid"

start_minidlna()
{
	@PREFIX@/sbin/minidlnad -f ${required_files}
}

load_rc_config ${name}
run_rc_command "$1"
