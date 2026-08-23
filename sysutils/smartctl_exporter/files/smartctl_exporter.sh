#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smartctl_exporter.sh,v 1.1 2026/08/23 11:56:02 tnn Exp $
#
# PROVIDE: smartctl_exporter
# REQUIRE: DAEMON

. /etc/rc.subr

name="smartctl_exporter"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args=" < /dev/null > /dev/null 2>&1 &"
smartctl_exporter_flags=${smartctl_exporter_flags:-"--web.listen-address=:9633 --log.level=error --smartctl.path=@PREFIX@/sbin/smartctl"}

load_rc_config $name
run_rc_command "$1"
