#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: memcached.sh,v 1.1 2010/02/27 20:40:52 morr Exp $
#

# PROVIDE: memcached
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="memcached"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="-d -u @MEMCACHED_USER@"

load_rc_config $name
run_rc_command "$1"
