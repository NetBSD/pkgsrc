#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: inspircd.sh,v 1.4 2019/08/23 10:51:48 nia Exp $
#
# PROVIDE: inspircd
# REQUIRE: DAEMON

. /etc/rc.subr

name="inspircd"
rcvar=${name}
command="@PREFIX@/bin/inspircd"
required_files="@PKG_SYSCONFDIR@/inspircd.conf"
pidfile="@PREFIX@/inspircd/${name}.pid"

inspircd_user="@INSPIRCD_USER@"
inspircd_group="@INSPIRCD_GROUP@"

load_rc_config $name
run_rc_command "$1"
