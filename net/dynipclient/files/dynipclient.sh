#!/bin/sh
#
# $NetBSD: dynipclient.sh,v 1.1 2001/08/28 13:23:06 tv Exp $
#
# PROVIDE: dynipclient
# REQUIRE: NETWORK

. /etc/rc.subr

name="dynipclient"
rcvar=$name
command="/usr/pkg/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="/etc/dynip.cfg"

load_rc_config $name
run_rc_command "$1"
