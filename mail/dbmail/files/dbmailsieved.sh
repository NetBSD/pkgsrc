#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailsieved.sh,v 1.1 2026/01/02 17:57:31 tnn Exp $
#

# PROVIDE: dbmailieved mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailsieved"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-sieved"
pidfile="@VARBASE@/run/dbmail/dbmail-sieved.pid"

load_rc_config $name
run_rc_command "$1"
