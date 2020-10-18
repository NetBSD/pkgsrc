#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: tinydyn.sh,v 1.1 2020/10/18 12:41:33 schmonz Exp $
#
# @PKGNAME@ master script for administrators to control tinydyndns
# services.
#

# KEYWORD: nostart

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcd_dir=`@DIRNAME@ $0`

# NOTE: run_rc_command sets $rc_arg
#
forward_commands() {
	tinydyndnsrcd $COMMAND_LIST
}

reverse_commands() {
	REVCOMMAND_LIST=
	for file in $COMMAND_LIST; do
		REVCOMMAND_LIST="$file $REVCOMMAND_LIST"
	done

	tinydyndnsrcd $REVCOMMAND_LIST
}

tinydyndnsrcd() {
	# Backward compat with NetBSD <1.6:
	[ -z "$rc_arg" ] && rc_arg=$_arg

	for service in "$@"; do
		if [ -f /etc/rc.subr ]; then
			load_rc_config $service
			if checkyesno $service; then
				$rcd_dir/${service} $rc_arg
			fi
		else
			$rcd_dir/${service} $rc_arg
		fi
	done
}

COMMAND_LIST="tinydyndns tinydynpop3d"

name="tinydyndns"
start_cmd="forward_commands"
stop_cmd="reverse_commands"
status_cmd="forward_commands"
extra_commands="status"

if [ -f /etc/rc.subr ]; then
	run_rc_command "$1"
else
	_arg="$1"
	${start_cmd}
fi
