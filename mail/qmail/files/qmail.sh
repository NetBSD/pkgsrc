#!/bin/sh
#
# $NetBSD: qmail.sh,v 1.1 2002/07/28 01:54:37 schmonz Exp $
#

# PROVIDE: mail
# REQUIRE: LOGIN

. /etc/rc.subr

name="qmail"
rcvar=${name}
required_files="@QMAILDIR@/rc @QMAILDIR@/control/me"
command="@QMAILDIR@/bin/qmail-send"
start_precmd="qmail_precmd"
extra_commands="reload"

qmail_precmd()
{
	command="@QMAILDIR@/rc"
	command_args="&"
}

load_rc_config $name
run_rc_command "$1"
