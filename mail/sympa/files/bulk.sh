#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: bulk.sh,v 1.1.2.2 2012/05/21 15:51:48 tron Exp $
#
# PROVIDE: bulk
# REQUIRE: sympa
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="bulk"
rcvar=$name
command="@PREFIX@/sympa/bin/bulk.pl"
pidfile="/var/sympa/run/bulk.pid"
command_interpreter="@PREFIX@/bin/perl"
sympa_user="sympa"

load_rc_config $name
run_rc_command "$1"
