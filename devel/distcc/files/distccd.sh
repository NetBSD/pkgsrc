#!/bin/sh
#
# $NetBSD: distccd.sh,v 1.1 2004/05/02 19:11:38 xtraeme Exp $
#

# PROVIDE: distccd
# BEFORE:  DAEMON

. /etc/rc.subr

name="distccd"
rcvar=$name
command="/usr/pkg/bin/${name}"
command_args='--daemon --pid-file /var/run/distccd.pid --user nobody'

load_rc_config $name
run_rc_command "$1"
