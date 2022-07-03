#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: snapclient.sh,v 1.1 2022/07/03 16:09:15 nia Exp $
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
snapclient_user=@SNAPCLIENT_USER@
snapclient_group=@SNAPCLIENT_GROUP@

load_rc_config $name
run_rc_command "$1"
