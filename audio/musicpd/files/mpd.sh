#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mpd.sh,v 1.1.1.1 2004/04/30 10:48:21 grant Exp $
#

# PROVIDE: mpd
# REQUIRE: DAEMON

. /etc/rc.subr

name="mpd"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/mpd.conf"

load_rc_config $name
run_rc_command "$1"
