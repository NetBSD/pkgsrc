#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: snapserver.sh,v 1.1 2022/07/03 16:09:15 nia Exp $
#
# PROVIDE: snapserver
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="snapserver"
rcvar=${name}
command="@PREFIX@/bin/snapserver"
command_args="-d"
pidfile="@VARBASE@/run/snapserver/pid"

load_rc_config $name
run_rc_command "$1"
