#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pptpd.sh,v 1.1 2005/01/01 06:26:41 cube Exp $
#

# PROVIDE: pptpd
# REQUIRE: DAEMON

. /etc/rc.subr

name="pptpd"
rcvar=$name
command="@PREFIX@/sbin/pptpd"
required_files="@PKG_SYSCONFDIR@/pptpd.conf"

load_rc_config $name
run_rc_command "$1"
