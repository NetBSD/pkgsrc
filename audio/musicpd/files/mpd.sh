#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mpd.sh,v 1.3 2023/12/05 13:05:23 triaxx Exp $
#

# PROVIDE: mpd
# REQUIRE: DAEMON
# KEYWORD: shutdown

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="mpd"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/mpd.conf"

load_rc_config $name
run_rc_command "$1"
