#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mpd.sh,v 1.2 2004/11/11 03:15:41 simonb Exp $
#

# PROVIDE: mpd
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="mpd"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/mpd.conf"

load_rc_config $name
run_rc_command "$1"
