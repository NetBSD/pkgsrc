#!/bin/sh
#
# $NetBSD: ups.sh,v 1.3 2001/11/21 16:29:13 jlam Exp $
#
# PROVIDE: ups
# KEYWORD: nostart

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

# NOTE: run_rc_command sets $_arg
#
forward_commands()
{
	for file in $COMMAND_LIST; do
		/etc/rc.d/$file $_arg
	done
}

reverse_commands()
{
	REVCOMMAND_LIST=
	for file in $COMMAND_LIST; do
		REVCOMMAND_LIST="$file $REVCOMMAND_LIST"
	done
	for file in $REVCOMMAND_LIST; do
		/etc/rc.d/$file $_arg
	done
}

COMMAND_LIST="upsdriver upsd upsmon upslog"

name="ups"
start_cmd="forward_commands"
stop_cmd="reverse_commands"
status_cmd="forward_commands"
extra_commands="status"

if [ ! -d /etc/rc.d ]
then
        @ECHO@ -n " ${name}"
	_arg="$1"
	${start_cmd}
else
        run_rc_command "$1"
fi
