#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: djbdns.sh,v 1.2 2017/08/05 15:16:05 schmonz Exp $
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
	djbdnsrcd $COMMAND_LIST
}

reverse_commands()
{
	REVCOMMAND_LIST=
	for file in $COMMAND_LIST; do
		REVCOMMAND_LIST="$file $REVCOMMAND_LIST"
	done

	djbdnsrcd $REVCOMMAND_LIST
}

djbdnsrcd()
{
	# Backward compat with NetBSD <1.6:
	[ -z "$rc_arg" ] && rc_arg=$_arg

	for service in "$@"; do
		if [ -f /etc/rc.subr ]; then
			load_rc_config $service
			checkyesno $service && $rcd_dir/${service} $rc_arg
		else
			$rcd_dir/${service} $rc_arg
		fi
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
