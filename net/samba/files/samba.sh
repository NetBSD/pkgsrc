#!/bin/sh
#
# $NetBSD: samba.sh,v 1.9 2002/01/10 12:01:37 jlam Exp $
#
# KEYWORD: nostart

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

rcd_dir=`@DIRNAME@ $0`

# NOTE: run_rc_command sets $_arg
#
forward_commands()
{
	for file in $COMMAND_LIST; do
		$rcd_dir/$file $_arg
	done
}

reverse_commands()
{
	REVCOMMAND_LIST=
	for file in $COMMAND_LIST; do
		REVCOMMAND_LIST="$file $REVCOMMAND_LIST"
	done
	for file in $REVCOMMAND_LIST; do
		$rcd_dir/$file $_arg
	done
}

COMMAND_LIST="nmbd smbd"

name="samba"
start_cmd="forward_commands"
stop_cmd="reverse_commands"
reload_cmd="forward_commands"
status_cmd="forward_commands"
extra_commands="reload status"

if [ -e /etc/rc.subr ]
then
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	_arg="$1"
	${start_cmd}
fi
