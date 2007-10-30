#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmail-timsieved.sh,v 1.1 2007/10/30 22:52:44 shannonjr Exp $
#

# PROVIDE: timsieved
# REQUIRE: 

. /etc/rc.subr

name="timsieved"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-timsieved"
pidfile="/var/run/dbmail-timsieved.pid"

load_rc_config $name
run_rc_command "$1"
