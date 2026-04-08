#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: vnstatd.sh,v 1.3 2026/04/08 16:08:47 sborrill Exp $
#

# PROVIDE: vnstatd
# REQUIRE: network mountcritlocal

$_rc_subr_loaded . /etc/rc.subr

name="vnstatd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
command_args="-d -p $pidfile"
dbdir="@VARBASE@/db/vnstat"
required_files="@PKG_SYSCONFDIR@/vnstat.conf"
start_precmd="${name}_precmd"

vnstatd_precmd()
{
	if [ ! -d $dbdir ]; then
		mkdir -p $dbdir
	fi
}

load_rc_config $name
run_rc_command "$1"
