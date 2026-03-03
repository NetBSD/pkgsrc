#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailpop3d.sh,v 1.4 2026/03/03 20:07:00 tnn Exp $
#

# PROVIDE: dbmailpop3 mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailpop3d"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-pop3d"
pidfile="@VARBASE@/run/dbmail/dbmail-pop3d.pid"
start_precmd="dbmailpop3d_precmd"

dbmailpop3d_precmd()
{
	if [ ! -d @VARBASE@/run/dbmail ]; then
		@MKDIR@ @VARBASE@/run/dbmail
		@CHMOD@ 0750 @VARBASE@/run/dbmail
		@CHOWN@ @DBMAIL_USER@:@DBMAIL_GROUP@ @VARBASE@/run/dbmail
	fi
}

load_rc_config $name
run_rc_command "$1"
