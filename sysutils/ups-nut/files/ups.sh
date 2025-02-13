#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ups.sh,v 1.12 2025/02/13 19:18:37 gdt Exp $
#
# KEYWORD: nostart

# NB: This file is not intended to be run automatically at boot.  It
# is a convenience script for humans to start or stop all 4 nut-ups
# daemons as a group.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcd_dir=`@DIRNAME@ $0`

# NOTE: run_rc_command sets $rc_arg
#
forward_commands()
{
	for file in $COMMAND_LIST; do
		$rcd_dir/$file $rc_arg
	done
}

reverse_commands()
{
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

if [ -f /etc/rc.subr ]; then
        run_rc_command "$1"
else
        @ECHO@ -n " ${name}"
	rc_arg="$1"
	${start_cmd}
fi
