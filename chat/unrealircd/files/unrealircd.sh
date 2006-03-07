#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: unrealircd.sh,v 1.2 2006/03/07 17:23:51 adrianp Exp $
#
# PROVIDE: unrealircd
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="unrealircd"
rcvar=${name}
command="@PREFIX@/sbin/ircd"
required_files="@UIRCD_HOME@/unrealircd.conf"
pidfile="@UIRCD_HOME@/ircd.pid"
unrealircd_user="@UIRCD_USER@"
unrealircd_group="@UIRCD_GROUP@"
extra_commands="rehash"
rehash_cmd="unrealircd_rehash"

unrealircd_rehash()
{
	kill -1 `@CAT@ $pidfile`
}

load_rc_config $name
run_rc_command "$1"
