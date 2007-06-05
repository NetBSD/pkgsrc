#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: freepopsd.sh,v 1.1.1.1 2007/06/05 05:56:01 schmonz Exp $
#

# PROVIDE: freepopsd
# REQUIRE: DAEMON LOGIN

# User-settable rc.conf variables and their default values:
: ${freepopsd_flags:="-l syslog -p 110"}

. /etc/rc.subr

name="freepopsd"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="-d -s @FREEPOPSD_USER@.@FREEPOPSD_GROUP@"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/config.lua"

load_rc_config $name
run_rc_command "$1"
