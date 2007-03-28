#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: task_manager.sh,v 1.1 2007/03/28 20:51:10 bouyer Exp $
#
# PROVIDE: task_manager
# REQUIRE: sympa
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="task_manager"
rcvar=$name
command="@PREFIX@/sympa/bin/task_manager.pl"
pidfile="/var/sympa/run/task_manager.pid"
command_interpreter="@PREFIX@/bin/perl"
sympa_user="sympa"

load_rc_config $name
run_rc_command "$1"
