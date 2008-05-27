#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: stunnel.sh,v 1.2 2008/05/27 11:51:32 tnn Exp $
#

# PROVIDE: stunnel
# REQUIRE: LOGIN

. /etc/rc.subr

name="stunnel"
rcvar=$name
command="@PREFIX@/bin/stunnel"
required_files="@PKG_SYSCONFDIR@/stunnel.conf"

load_rc_config $name
run_rc_command "$1"
