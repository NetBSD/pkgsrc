#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: node_exporter.sh,v 1.1 2022/12/25 17:46:15 bsiegert Exp $
#
# PROVIDE: node_exporter
# REQUIRE: DAEMON

. /etc/rc.subr

name="node_exporter"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args=" &"
node_exporter_flags=${node_exporter_flags:-"--web.listen-address=:9100 --log.level=error"}

load_rc_config $name
run_rc_command "$1"
