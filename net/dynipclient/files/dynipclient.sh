#!/bin/sh
#
# $NetBSD: dynipclient.sh,v 1.2 2002/09/23 14:52:14 grant Exp $
#
# PROVIDE: dynipclient
# REQUIRE: NETWORK

. /etc/rc.subr

name="dynipclient"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="/etc/dynip.cfg"

load_rc_config $name
run_rc_command "$1"
