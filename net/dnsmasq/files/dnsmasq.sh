#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dnsmasq.sh,v 1.2.28.1 2015/04/29 18:40:55 spz Exp $
#

# PROVIDE: dnsmasq
# REQUIRE: DAEMON SERVERS

. /etc/rc.subr

name="dnsmasq"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
