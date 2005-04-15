#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: djbdns.sh,v 1.1 2005/04/15 05:15:55 schmonz Exp $
#
# @PKGNAME@ master script for administrators to control djbdns
# services.
#
# For Red Hat chkconfig
# chkconfig: - 55 45
# description: DJB's collection of DNS tools
#

# KEYWORD: nostart

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

djbdnsrcd()
{
	for service in $@; do
		$rcd_dir/${service} $rc_arg
	done
}

COMMAND_LIST="axfrdns dnscache rbldns tinydns"

name="djbdns"
start_cmd="forward_commands"
stop_cmd="reverse_commands"
reload_cmd="djbdnsrcd axfrdns rbldns tinydns"; cdb_cmd=${reload_cmd}
status_cmd="forward_commands"
extra_commands="status cdb reload"

if [ -f /etc/rc.subr ]; then
	run_rc_command "$1"
else
	_arg="$1"
	${start_cmd}
fi
