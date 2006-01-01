#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: daapd.sh,v 1.4 2006/01/01 18:32:01 tron Exp $
#

# PROVIDE: daapd
# REQUIRE: DAEMON LOGIN howl

. /etc/rc.subr

name="daapd"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/daapd.conf"
command_args="</dev/null 2>&1 > /dev/null &"

load_rc_config $name
run_rc_command "$1"
