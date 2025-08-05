#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: shairport-sync.sh,v 1.2 2025/08/05 19:33:02 schmonz Exp $
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
start_precmd="shairport_sync_precmd"

shairport_sync_precmd() {
	@MKDIR@ "@VARBASE@/run/shairport-sync"
	@CHOWN@ ${shairport_user}:${shairport_group} "@VARBASE@/run/shairport-sync"
	if [ "$(id -u ${shairport_user})" != 0 ] && [ "$(@UNAME@)" = "NetBSD" ]; then
		/sbin/sysctl -w hw.audio0.multiuser=1
	fi
}

load_rc_config $name
run_rc_command "$1"
