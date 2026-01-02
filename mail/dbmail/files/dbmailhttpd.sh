#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailhttpd.sh,v 1.1 2026/01/02 17:57:31 tnn Exp $
#

# PROVIDE: dbmailhttp mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailhttpd"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-httpd"
pidfile="@VARBASE@/run/dbmail/dbmail-httpd.pid"

load_rc_config $name
run_rc_command "$1"
