#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: samba.sh,v 1.3 2005/06/19 18:38:40 taca Exp $
#
# KEYWORD: nostart
#
#	This script is intended for the end-user.
#	It is not started by /etc/rc.
#	It manipulates various samba services (smbd, nmbd, winbindd),
#	which are controlled via their appropriate rc.conf(5) settings.
#

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

COMMAND_LIST="nmbd smbd winbindd"

name="samba"
start_cmd="forward_commands"
stop_cmd="reverse_commands"
reload_cmd="forward_commands"
status_cmd="forward_commands"
extra_commands="reload status"

if [ -f /etc/rc.subr ]; then
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	_arg="$1"
	${start_cmd}
fi
