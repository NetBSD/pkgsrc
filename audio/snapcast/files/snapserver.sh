#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: snapserver.sh,v 1.2 2022/07/06 10:02:14 nia Exp $
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
start_precmd="snapserver_precmd"

snapserver_precmd()
{
	if [ ! -d "@VARBASE@/run/snapserver" ]; then
		mkdir -p -m 755 "@VARBASE@/run/snapserver"
		chown @SNAPSERVER_USER@:@SNAPSERVER_GROUP@ "@VARBASE@/run/snapserver"
	fi
}

load_rc_config $name
run_rc_command "$1"
