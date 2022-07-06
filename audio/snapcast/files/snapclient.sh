#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: snapclient.sh,v 1.2 2022/07/06 10:02:14 nia Exp $
#
# PROVIDE: snapclient
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="snapclient"
rcvar=${name}
command="@PREFIX@/bin/snapclient"
command_args="-d"
pidfile="@VARBASE@/run/snapclient/pid"
snapclient_user="@SNAPCLIENT_USER@"
snapclient_group="@SNAPCLIENT_GROUP@"
start_precmd="snapclient_precmd"

snapclient_precmd()
{
	if [ ! -d "@VARBASE@/run/snapclient" ]; then
		mkdir -p -m 755 "@VARBASE@/run/snapclient"
		chown @SNAPCLIENT_USER@:@SNAPCLIENT_GROUP@ "@VARBASE@/run/snapclient"
	fi
}

load_rc_config $name
run_rc_command "$1"
