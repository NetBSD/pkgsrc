#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmail.sh,v 1.2 2007/11/03 11:39:50 obache Exp $
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

dbmailrcd()
{
	for service in $@; do
		$rcd_dir/dbmail${service} $rc_arg
	done
}

COMMAND_LIST="dbmailimapd dbmailpop3d dbmaillmtpd @TIMSIEVED@"

name="dbmail"
start_cmd="forward_commands"
stop_cmd="reverse_commands"
status_cmd="forward_commands"
extra_commands="status"

if [ -f /etc/rc.subr ]; then
	run_rc_command "$1"
else
	_arg="$1"
	${start_cmd}
fi
