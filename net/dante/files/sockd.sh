#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sockd.sh,v 1.1 2007/12/04 13:30:06 abs Exp $
#
# PROVIDE: sockd
# REQUIRE: DAEMON

. /etc/rc.subr

name="sockd"
command="@PREFIX@/sbin/${name}"
command_args="-D" # run as a daemon
required_files="@PKG_SYSCONFDIR@/sockd.conf"

load_rc_config $name
run_rc_command "$1"
