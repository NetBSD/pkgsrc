#!/bin/sh
#
# $NetBSD: ups.sh,v 1.5 2001/11/22 00:55:51 lukem Exp $
#
# KEYWORD: nostart

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

# NOTE: run_rc_command sets $_arg
#
forward_commands()
{
	for file in $COMMAND_LIST; do
		@RCD_SCRIPTS_DIR@/$file $_arg
	done
}

reverse_commands()
{
	REVCOMMAND_LIST=
	for file in $COMMAND_LIST; do
		REVCOMMAND_LIST="$file $REVCOMMAND_LIST"
	done
	for file in $REVCOMMAND_LIST; do
		@RCD_SCRIPTS_DIR@/$file $_arg
	done
}

COMMAND_LIST="upsdriver upsd upsmon upslog"

name="ups"
start_cmd="forward_commands"
stop_cmd="reverse_commands"
status_cmd="forward_commands"
extra_commands="status"

if [ -e /etc/rc.subr ]
then
        run_rc_command "$1"
else
        @ECHO@ -n " ${name}"
	_arg="$1"
	${start_cmd}
fi
