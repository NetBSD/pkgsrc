#!/bin/sh
#
# $NetBSD: samba.sh,v 1.4 2001/11/21 21:38:54 jlam Exp $
#
# PROVIDE: samba
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
