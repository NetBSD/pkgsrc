#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dnsmasq.sh,v 1.2 2011/10/07 22:37:04 shattered Exp $
#

# PROVIDE: dnsmasq
# REQUIRE: DAEMON SERVERS

. /etc/rc.subr

name="dnsmasq"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
