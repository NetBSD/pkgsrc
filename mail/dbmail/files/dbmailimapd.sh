#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailimapd.sh,v 1.3 2026/01/02 17:57:31 tnn Exp $
#

# PROVIDE: dbmailimap mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailimapd"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-imapd"
pidfile="@VARBASE@/run/dbmail/dbmail-imapd.pid"

load_rc_config $name
run_rc_command "$1"
