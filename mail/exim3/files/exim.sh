#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: exim.sh,v 1.3 2004/05/06 22:34:27 reed Exp $
#
# PROVIDE: mail
# REQUIRE: LOGIN

. /etc/rc.subr

name="exim"
exim_flags=${exim_flags-"-bd -q30m"}
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/configure"

load_rc_config $name
run_rc_command "$1"
