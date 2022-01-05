#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sleepwatcher.sh,v 1.1 2022/01/05 10:56:00 schmonz Exp $
#
# PROVIDE: sleepwatcher
# REQUIRE: LOGIN

. /etc/rc.subr

name="sleepwatcher"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="-d -V -s @PREFIX@/sbin/sleepwatcher-sleep -w @PREFIX@/sbin/sleepwatcher-wakeup"

load_rc_config $name
run_rc_command $1
