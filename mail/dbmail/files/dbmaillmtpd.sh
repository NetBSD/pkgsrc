#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmaillmtpd.sh,v 1.4 2026/03/03 20:07:00 tnn Exp $
#

# PROVIDE: dbmaillmtp mail
# REQUIRE: 

. /etc/rc.subr

name="dbmaillmtpd"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-lmtpd"
pidfile="@VARBASE@/run/dbmail/dbmail-lmtpd.pid"
start_precmd="dbmaillmtpd_precmd"

dbmaillmtpd_precmd()
{
	if [ ! -d @VARBASE@/run/dbmail ]; then
		@MKDIR@ @VARBASE@/run/dbmail
		@CHMOD@ 0750 @VARBASE@/run/dbmail
		@CHOWN@ @DBMAIL_USER@:@DBMAIL_GROUP@ @VARBASE@/run/dbmail
	fi
}

load_rc_config $name
run_rc_command "$1"
