#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailsieved.sh,v 1.2 2026/03/03 20:07:00 tnn Exp $
#

# PROVIDE: dbmailieved mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailsieved"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-sieved"
pidfile="@VARBASE@/run/dbmail/dbmail-sieved.pid"
start_precmd="dbmailsieved_precmd"

dbmailsieved_precmd()
{
	if [ ! -d @VARBASE@/run/dbmail ]; then
		@MKDIR@ @VARBASE@/run/dbmail
		@CHMOD@ 0750 @VARBASE@/run/dbmail
		@CHOWN@ @DBMAIL_USER@:@DBMAIL_GROUP@ @VARBASE@/run/dbmail
	fi
}

load_rc_config $name
run_rc_command "$1"
