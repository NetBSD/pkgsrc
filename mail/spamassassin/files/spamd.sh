#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: spamd.sh,v 1.5 2002/09/20 02:01:57 grant Exp $
#
# PROVIDE: spamd
# REQUIRE: DAEMON

. /etc/rc.subr

name="spamd"                      
rcvar=$name         
command="@PREFIX@/bin/${name}"
command_args="-d -r /var/run/${name}.pid"
command_interpreter="@PREFIX@/bin/perl"
pidfile="/var/run/${name}.pid"
              
load_rc_config $name
run_rc_command "$1"
