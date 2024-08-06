#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: node_exporter.sh,v 1.2 2024/08/06 02:27:53 tnn Exp $
#
# PROVIDE: node_exporter
# REQUIRE: DAEMON

. /etc/rc.subr

name="node_exporter"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args=" < /dev/null > /dev/null 2>&1 &"
node_exporter_flags=${node_exporter_flags:-"--web.listen-address=:9100 --log.level=error"}

load_rc_config $name
run_rc_command "$1"
