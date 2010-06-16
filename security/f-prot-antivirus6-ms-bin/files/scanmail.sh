#!@RCD_SCRIPTS_SHELL@
# $NetBSD: scanmail.sh,v 1.2 2010/06/16 22:27:04 taca Exp $

# PROVIDE: scanmail
# REQUIRE: fpscand
# BEFORE: mail

. /etc/rc.subr

name="scanmail"
rcvar=$name
command="@PREFIX@/@FPROTDIR@/scan-mail.pl"
command_interpreter="@PREFIX@/bin/perl"
pidfile="@VARDIR@/run/scan-mail.pid"
datadir="@VARDIR@"
required_files="${command}"
command_args="--daemon"
user="@FPROT_USER@"
start_cmd="scanmail_start"

scanmail_start()
{
	if [ -x ${command} ]; then
		su ${user} -c "${command} ${command_args} ${rc_flags}"
	fi
}

load_rc_config $name
run_rc_command "$1"
