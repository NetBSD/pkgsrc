#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sympa.sh,v 1.2 2015/09/26 14:56:10 bouyer Exp $
#
# PROVIDE: sympa
# REQUIRE: mail
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="sympa"
rcvar=$name
command="@PREFIX@/sympa/bin/sympa_msg.pl"
pidfile="/var/sympa/run/sympa_msg.pid"
command_interpreter="@PREFIX@/bin/perl"
sympa_user="sympa"

load_rc_config $name
run_rc_command "$1"
