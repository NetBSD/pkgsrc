#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailpop3d.sh,v 1.1 2005/01/09 04:17:39 schmonz Exp $
#

# PROVIDE: dbmailpop3 mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailpop3d"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-pop3d"
pidfile="/var/run/dbmail-pop3d.pid"

load_rc_config $name
run_rc_command "$1"
