#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dynipclient.sh,v 1.3 2003/07/30 12:01:26 jmmv Exp $
#
# PROVIDE: dynipclient
# REQUIRE: NETWORK

. /etc/rc.subr

name="dynipclient"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/dynip.cfg"

load_rc_config $name
run_rc_command "$1"
