#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rsyncd.sh,v 1.1 2009/02/21 09:34:17 tron Exp $
#
# PROVIDE: rsyncd
# REQUIRE: DAEMON

. /etc/rc.subr

name="rsyncd"
rcvar=$name
command="@PREFIX@/bin/rsync"
required_files="@PKG_SYSCONFDIR@/rsyncd.conf"

command_args="--daemon"

load_rc_config $name
run_rc_command "$1"
