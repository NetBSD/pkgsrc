#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pxe.sh,v 1.1 2003/07/30 18:09:27 jmmv Exp $
#
# PROVIDE: pxe
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="pxe"
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

load_rc_config $name
run_rc_command "$1"
