#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailimapd.sh,v 1.4 2026/03/03 20:07:00 tnn Exp $
#

# PROVIDE: dbmailimap mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailimapd"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-imapd"
pidfile="@VARBASE@/run/dbmail/dbmail-imapd.pid"
start_precmd="dbmailimapd_precmd"

dbmailimapd_precmd()
{
	if [ ! -d @VARBASE@/run/dbmail ]; then
		@MKDIR@ @VARBASE@/run/dbmail
		@CHMOD@ 0750 @VARBASE@/run/dbmail
		@CHOWN@ @DBMAIL_USER@:@DBMAIL_GROUP@ @VARBASE@/run/dbmail
	fi
}

load_rc_config $name
run_rc_command "$1"
