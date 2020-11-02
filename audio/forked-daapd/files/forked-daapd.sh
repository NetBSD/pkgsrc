#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: forked-daapd.sh,v 1.1 2020/11/02 14:00:47 nia Exp $
#
# PROVIDE: daapd
# REQUIRE: mdnsd
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="daapd"
rcvar=${name}
command="@PREFIX@/sbin/forked-daapd"
command_args="-P @VARBASE@/run/forked-daapd.pid"
pidfile="@VARBASE@/run/forked-daapd.pid"

load_rc_config $name
run_rc_command "$1"
