#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmaillmtpd.sh,v 1.1 2005/01/09 04:17:39 schmonz Exp $
#

# PROVIDE: dbmaillmtp mail
# REQUIRE: 

. /etc/rc.subr

name="dbmaillmtpd"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-lmtpd"
pidfile="/var/run/dbmail-lmtpd.pid"

load_rc_config $name
run_rc_command "$1"
