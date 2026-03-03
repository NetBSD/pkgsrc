#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailhttpd.sh,v 1.2 2026/03/03 20:07:00 tnn Exp $
#

# PROVIDE: dbmailhttp mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailhttpd"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-httpd"
pidfile="@VARBASE@/run/dbmail/dbmail-httpd.pid"
start_precmd="dbmailhttpd_precmd"

dbmailhttpd_precmd()
{
	if [ ! -d @VARBASE@/run/dbmail ]; then
		@MKDIR@ @VARBASE@/run/dbmail
		@CHMOD@ 0750 @VARBASE@/run/dbmail
		@CHOWN@ @DBMAIL_USER@:@DBMAIL_GROUP@ @VARBASE@/run/dbmail
	fi
}

load_rc_config $name
run_rc_command "$1"
