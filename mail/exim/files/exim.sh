#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: exim.sh,v 1.5 2003/09/02 10:33:40 abs Exp $
#
# PROVIDE: mail
# REQUIRE: LOGIN

. /etc/rc.subr

name="exim"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/configure"

load_rc_config $name
run_rc_command "$1"
