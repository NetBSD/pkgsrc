#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ircservices.sh,v 1.1 2004/10/02 22:09:46 adrianp Exp $
#
# PROVIDE: ircservices
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="ircservices"
rcvar=$name
command="@PREFIX@/sbin/ircservices"
required_files="@PREFIX@/lib/services/ircservices.conf"
command_args=""

load_rc_config $name
run_rc_command "$1"
