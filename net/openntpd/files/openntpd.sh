#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: openntpd.sh,v 1.1.1.1 2004/07/19 19:17:25 xtraeme Exp $
#

# PROVIDE: openntpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

. /etc/rc.subr

name="ntpd"
rcvar="openntpd"
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/ntpd.conf"

load_rc_config $name
run_rc_command "$1"
