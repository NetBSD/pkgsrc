#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailimapd.sh,v 1.1 2005/01/09 04:17:39 schmonz Exp $
#

# PROVIDE: dbmailimap mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailimapd"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-imapd"
pidfile="/var/run/dbmail-imapd.pid"

load_rc_config $name
run_rc_command "$1"
