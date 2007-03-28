#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sympa.sh,v 1.1 2007/03/28 20:51:10 bouyer Exp $
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
command="@PREFIX@/sympa/bin/sympa.pl"
pidfile="/var/sympa/run/sympa.pid"
command_interpreter="@PREFIX@/bin/perl"
sympa_user="sympa"

load_rc_config $name
run_rc_command "$1"
