#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: exim.sh,v 1.4 2003/08/02 17:00:09 jmmv Exp $
#
# PROVIDE: mail
# REQUIRE: LOGIN
#

. /etc/rc.subr

name="exim"                      
rcvar=$name         
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/configure"
              
load_rc_config $name
run_rc_command "$1"
