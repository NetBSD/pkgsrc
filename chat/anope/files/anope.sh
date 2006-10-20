#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: anope.sh,v 1.1.1.1 2006/10/20 22:40:24 adrianp Exp $
#
# PROVIDE: anope
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="anope"
rcvar=${name}
command="@PREFIX@/lib/anope/services"
required_files="@PREFIX@/lib/anope/services.conf"
anope_user="@ANOPE_USER@"
anope_group="@ANOPE_GROUP@"

load_rc_config $name
run_rc_command "$1"
