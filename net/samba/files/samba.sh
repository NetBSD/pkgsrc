#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: samba.sh,v 1.18 2005/11/14 14:01:49 jlam Exp $
#
# KEYWORD: nostart
#
#	This script is intended for the end-user.
#	It is not started by /etc/rc.
#	It manipulates various samba services (smbd, nmbd, winbindd),
#	which are controlled via their appropriate rc.conf(5) settings.
#

. /etc/rc.subr

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

COMMAND_LIST="nmbd @WINBINDD_RCD_SCRIPT@ smbd"

name="samba"
start_cmd="forward_commands"
stop_cmd="reverse_commands"
reload_cmd="forward_commands"
status_cmd="forward_commands"
extra_commands="reload status"

run_rc_command "$1"
