#!/bin/sh
#
#	$NetBSD: spamd.sh,v 1.3 2002/09/05 09:03:33 hubertf Exp $
#
# PROVIDE: spamd
# REQUIRE: DAEMON

. /etc/rc.subr

name="spamd"                      
rcvar=$name         
command="/usr/pkg/bin/${name}"
command_args="-d -r /var/run/${name}.pid"
command_interpreter="@PREFIX@/bin/perl"
pidfile="/var/run/${name}.pid"
              
load_rc_config $name
run_rc_command "$1"
