#!/bin/sh
#
# $NetBSD: dnsmasq.sh,v 1.1.1.1 2005/10/18 04:41:59 minskim Exp $
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
