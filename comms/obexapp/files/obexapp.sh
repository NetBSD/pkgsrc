#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: obexapp.sh,v 1.3 2012/06/16 19:28:19 plunky Exp $
#
# PROVIDE: obexapp
# REQUIRE: @RCD_SDPD@
#

# variables used:
#
#	obexapp_channel		RFCOMM channel number
#	obexapp_username	username for -u option
#	obexapp_pathname	pathname for -r option

$rc_subr_loaded . /etc/rc.subr

name="obexapp"
rcvar=$name
command="@PREFIX@/bin/${name}"

load_rc_config ${name}

command_args="-s -S -r ${obexapp_pathname:-@VARBASE@/spool/obex}"

if @TEST@ "${obexapp_channel}"; then
	command_args="${command_args} -C ${obexapp_channel}"
fi

if @TEST@ "${obexapp_username}"; then
	command_args="${command_args} -u ${obexapp_username}"
fi

run_rc_command "$1"
