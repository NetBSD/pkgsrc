#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: vnstatd.sh,v 1.1.1.1 2009/11/19 15:48:19 sborrill Exp $
#

# PROVIDE: vnstatd
# REQUIRE: network mountcritlocal

$_rc_subr_loaded . /etc/rc.subr

name="vnstatd"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
command_args="-d -p $pidfile"
required_dirs="@VARBASE@/db/vnstat"
required_files="@PKG_SYSCONFDIR@/vnstat.conf"

load_rc_config $name
run_rc_command "$1"
