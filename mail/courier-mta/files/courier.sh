#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courier.sh,v 1.2 2007/08/10 17:57:04 jlam Exp $
#
# KEYWORD: nostart
#
#	This script is intended for the end-user.
#	It is not started by /etc/rc.
#	It manipulates various Courier mail services which are
#	controlled via their appropriate rc.conf(5) settings.
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
		@TEST@ ! -x "$rcd_dir/$file" || $rcd_dir/$file $rc_arg
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
		@TEST@ ! -x "$rcd_dir/$file" || $rcd_dir/$file $rc_arg
	done
}

COMMAND_LIST=
COMMAND_LIST="$COMMAND_LIST courierfilter"
COMMAND_LIST="$COMMAND_LIST @COURIERLDAPALIASD@"
COMMAND_LIST="$COMMAND_LIST courierd"
COMMAND_LIST="$COMMAND_LIST courieresmtp"
COMMAND_LIST="$COMMAND_LIST courieresmtpmsa"
COMMAND_LIST="$COMMAND_LIST courieresmtps"
COMMAND_LIST="$COMMAND_LIST courierimap"
COMMAND_LIST="$COMMAND_LIST courierimaps"
COMMAND_LIST="$COMMAND_LIST courierpop"
COMMAND_LIST="$COMMAND_LIST courierpops"
COMMAND_LIST="$COMMAND_LIST sqwebmail"
COMMAND_LIST="$COMMAND_LIST webmlm"

name="courier"
start_cmd="forward_commands"
stop_cmd="reverse_commands"
extra_commands="reload status"

run_rc_command "$1"
