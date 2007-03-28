#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: archived.sh,v 1.1 2007/03/28 20:51:10 bouyer Exp $
#
# PROVIDE: archived
# REQUIRE: sympa
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="archived"
rcvar=$name
command="@PREFIX@/sympa/bin/archived.pl"
pidfile="/var/sympa/run/archived.pid"
command_interpreter="@PREFIX@/bin/perl"
sympa_user="sympa"

load_rc_config $name
run_rc_command "$1"
