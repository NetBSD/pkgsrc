#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: distccd.sh,v 1.2 2004/05/02 19:31:48 xtraeme Exp $
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
