#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: hitch.sh,v 1.1 2016/05/25 20:15:35 fhajny Exp $
#

# PROVIDE: hitch
# REQUIRE: LOGIN

. /etc/rc.subr

name="hitch"
rcvar=$name
command="@PREFIX@/sbin/hitch"
command_args="--config=@PKG_SYSCONFDIR@/hitch.conf"
required_files="@PKG_SYSCONFDIR@/hitch.conf"

load_rc_config $name
run_rc_command "$1"
