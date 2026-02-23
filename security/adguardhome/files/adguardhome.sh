#!@RCD_SCRIPTS_SHELL@

# PROVIDE: adguardhome
# REQUIRE: DAEMON
# BEFORE:  LOGIN

. /etc/rc.subr

name="AdGuardHome"
rcvar="adguardhome"
command="@PREFIX@/bin/${name}"
command_args="--no-check-update -c @PKG_SYSCONFDIR@/AdGuardHome.yaml -w @PREFIX@/libdata/adguardhome --pidfile @VARBASE@/run/${name}.pid -l syslog &"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
