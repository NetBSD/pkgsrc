#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: daapd.sh,v 1.3 2005/01/08 06:44:41 schmonz Exp $
#

# PROVIDE: daapd
# REQUIRE: DAEMON LOGIN howl

. /etc/rc.subr

name="daapd"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/daapd.conf"
command_args="-c $required_files 2>&1 > /dev/null &"

load_rc_config $name
run_rc_command "$1"
