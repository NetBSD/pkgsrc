#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmail.sh,v 1.2 2002/09/20 02:01:57 grant Exp $
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
