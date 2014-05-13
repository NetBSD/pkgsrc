#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dnsbl-milter.sh,v 1.1 2014/05/13 15:31:40 sborrill Exp $
#

# PROVIDE: dnsblmilter
# REQUIRE: DAEMON
# BEFORE:  LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="dnsblmilter"
pidfile="@VARBASE@/run/dnsbl.pid"
rcvar=$name
command="@PREFIX@/sbin/dnsbl"
command_args="-p local:@VARBASE@/run/dnsbl.sock -r @VARBASE@/run/dnsbl-resolver.sock"
required_files="@PKG_SYSCONFDIR@/dnsbl.conf"

load_rc_config $name
run_rc_command "$1"
