#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailpop3d.sh,v 1.2 2004/04/27 03:05:09 schmonz Exp $
#

# PROVIDE: mail
# REQUIRE: qmail

. /etc/rc.subr

name="qmailpop3d"
rcvar=${name}
required_files="@QMAILDIR@/control/me"
command="@LOCALBASE_NORMAL@/bin/tcpserver"
procname=${name}
start_precmd="qmailpop3d_precmd"

if [ -z "$qmailpop3d_flags" ]; then
	qmailpop3d_flags="-v -H -R -l 0"
fi

qmailpop3d_precmd()
{
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for POP
	# service. Use argv0(1) to set procname to "qmailpop3d".
	command="@SETENV@ - @LOCALBASE_NORMAL@/bin/argv0 @LOCALBASE_NORMAL@/bin/tcpserver $name $qmailpop3d_flags 0 110 @QMAILDIR@/bin/qmail-popup `@CAT@ @QMAILDIR@/control/me` @LOCALBASE_NORMAL@/bin/checkpassword @QMAILDIR@/bin/qmail-pop3d Maildir 2>&1 | @QMAILDIR@/bin/splogger pop3d 3"
	command_args="&"
	rc_flags=""
}

load_rc_config $name
run_rc_command "$1"
