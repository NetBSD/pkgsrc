#!/bin/sh
#
# $NetBSD: ups.sh,v 1.1 2001/11/21 15:50:55 jlam Exp $
#
# PROVIDE: ups
# KEYWORD: nostart

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

# NOTE: run_rc_command sets $_arg
#
ups_commands()
{
	for file in $UPS_COMMANDS; do
		/etc/rc.d/$file $_arg
	done
}

ups_reversecommands()
{
	UPS_REVCOMMANDS=
	for file in $UPS_COMMANDS; do
		UPS_REVCOMMANDS="$file $UPS_REVCOMMANDS"
	done
	for file in $UPS_REVCOMMANDS; do
		/etc/rc.d/$file $_arg
	done
}

UPS_COMMANDS="upsdriver upsd upsmon upslog"

name="ups"
start_cmd="ups_commands"
stop_cmd="ups_reversecommands"
status_cmd="ups_commands"
extra_commands="status"
run_rc_command "$1"

if [ ! -d /etc/rc.d ]
then
        @ECHO@ -n " ${name}"
	${start_cmd} "$1"
else
        run_rc_command "$1"
fi
