#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmail.sh,v 1.3 2004/08/23 03:47:48 schmonz Exp $
#
# @PKGNAME@ master script for administrators to control qmail
# services. Usage resembles the qmailctl script from "Life with qmail".
#
# For Red Hat chkconfig
# chkconfig: - 80 30
# description: the qmail MTA
#

# KEYWORD: nostart

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcd_dir=`@DIRNAME@ $0`

# NOTE: run_rc_command sets $rc_arg
#
forward_commands()
{
	# Backward compat with NetBSD <1.6:
	[ -z "$rc_arg" ] && rc_arg=$_arg

	for file in $COMMAND_LIST; do
		$rcd_dir/$file $rc_arg
	done
}

reverse_commands()
{
	# Backward compat with NetBSD <1.6:
	[ -z "$rc_arg" ] && rc_arg=$_arg

	REVCOMMAND_LIST=
	for file in $COMMAND_LIST; do
		REVCOMMAND_LIST="$file $REVCOMMAND_LIST"
	done
	for file in $REVCOMMAND_LIST; do
		$rcd_dir/$file $rc_arg
	done
}

qmailrcd()
{
	for service in $@; do
		$rcd_dir/qmail${service} $rc_arg
	done
}

qmail_help()
{
	@CAT@ <<HELP
   stop -- stops mail service (smtp connections refused, nothing goes out)
  start -- starts mail service (smtp connection accepted, mail can go out)
  pause -- temporarily stops mail service (connections accepted, nothing leaves)
   cont -- continues paused mail service
   stat -- displays status of mail service
    cdb -- rebuild the tcpserver cdb file for smtp and/or pop3
restart -- stops and restarts smtp, sends qmail-send a TERM & restarts it
doqueue -- schedules queued messages for immediate delivery
 reload -- sends qmail-send HUP, rereading locals and virtualdomains
  queue -- shows status of queue
   alrm -- same as doqueue
  flush -- same as doqueue
    hup -- same as reload
HELP
}

COMMAND_LIST="qmailsend qmailsmtpd qmailpop3d"

name="qmail"
start_cmd="forward_commands"
stop_cmd="reverse_commands"
doqueue_cmd="qmailrcd send"; alrm_cmd=${doqueue_cmd}; flush_cmd=${doqueue_cmd}
reload_cmd="qmailrcd send"; hup_cmd=${reload_cmd}
status_cmd="forward_commands"; stat_cmd=${status_cmd}
pause_cmd="forward_commands"
cont_cmd="forward_commands"
cdb_cmd="qmailrcd smtpd pop3d"
queue_cmd="qmailrcd send"
help_cmd="qmail_help"
extra_commands="pause cont stat status cdb doqueue reload queue alrm flush hup help"

if [ -f /etc/rc.subr ]; then
	run_rc_command "$1"
else
	_arg="$1"
	${start_cmd}
fi
