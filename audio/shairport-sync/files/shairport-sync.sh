#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: shairport-sync.sh,v 1.1 2022/07/01 18:36:27 nia Exp $
#
# PROVIDE: shairport
# REQUIRE: mdnsd
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="shairport"
rcvar=${name}
command="@PREFIX@/bin/shairport-sync"
command_args="-d"
shairport_user="@SHAIRPORT_USER@"
shairport_group="@SHAIRPORT_GROUP@"
pidfile="@VARBASE@/run/shairport-sync/shairport-sync.pid"

load_rc_config $name
run_rc_command "$1"
