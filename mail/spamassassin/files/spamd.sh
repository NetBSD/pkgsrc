#!/bin/sh
#
#	$NetBSD: spamd.sh,v 1.2 2002/08/30 11:17:10 abs Exp $
#
# PROVIDE: spamd
# REQUIRE: DAEMON

. /etc/rc.subr

name="spamd"                      
rcvar=$name         
command="/usr/pkg/bin/${name}"
command_args="-r /var/run/${name}.pid"
command_interpreter="@PREFIX@/bin/perl"
pidfile="/var/run/${name}.pid"
              
load_rc_config $name
run_rc_command "$1"
