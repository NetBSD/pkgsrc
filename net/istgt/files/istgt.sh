#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: istgt.sh,v 1.2 2012/07/27 13:08:54 sborrill Exp $
#

# PROVIDE: istgt
# REQUIRE: network mountcritlocal

$_rc_subr_loaded . /etc/rc.subr

name="istgt"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/istgt.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
