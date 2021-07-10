#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: openntpd.sh,v 1.2 2021/07/10 18:32:15 dholland Exp $
#

# PROVIDE: openntpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

. /etc/rc.subr

name="ntpd"
rcvar="openntpd"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/ntpd.conf"
start_precmd="$openntpd_precmd"

openntpd_precmd()
{
	rc_flags="-p ${pidfile} $rc_flags"
}

load_rc_config $name
run_rc_command "$1"
