#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: obexapp.sh,v 1.1 2007/03/01 21:39:09 plunky Exp $
#
# PROVIDE: obexapp
# REQUIRE: sdpd
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

if @TEST@ -z "${obexapp_channel}"; then
	err 1 "Must specify obexapp_channel"
fi

command_args="-s -S -C ${obexapp_channel} -r ${obexapp_pathname:-@VARBASE@/spool/obex}"

if @TEST@ "${obexapp_username}"; then
	command_args="${command_args} -u ${obexapp_username}"
fi

run_rc_command "$1"
