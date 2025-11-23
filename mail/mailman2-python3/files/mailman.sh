#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mailman.sh,v 1.1 2025/11/23 16:29:45 christos Exp $
#
# PROVIDE: mailman
# REQUIRE: mail
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="mailman"
rcvar=$name
ctl_command="@PREFIX@/lib/mailman/bin/mailmanctl"
start_cmd="mailman_doit -s start"
stop_cmd="mailman_doit stop"
restart_cmd="mailman_doit restart"

mailman_doit ()
{
	${ctl_command} $*
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	mailman_doit "$1"
fi
