#!/bin/sh
#
# $NetBSD: ups.sh,v 1.7.2.1 2002/06/23 19:01:12 jlam Exp $
#
# KEYWORD: nostart

if [ -f /etc/rc.subr ]
then
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

COMMAND_LIST="upsdriver upsd upsmon upslog"

name="ups"
start_cmd="forward_commands"
stop_cmd="reverse_commands"
status_cmd="forward_commands"
extra_commands="status"

if [ -f /etc/rc.subr ]
then
        run_rc_command "$1"
else
        @ECHO@ -n " ${name}"
	_arg="$1"
	${start_cmd}
fi
