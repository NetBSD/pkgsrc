#! /bin/sh
#
# Service Location Protocol daemon
#
# PROVIDE: slpd
# REQUIRE: DAEMON

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="slpd"
rcvar=${name}
command="@PREFIX@/sbin/slpd"
pidfile="/var/run/slpd.pid"
required_files="/etc/slp.conf"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n " ${name}"
	exec ${command} ${slpd_flags} ${command_args}
fi

load_rc_config $name
run_rc_command "$1"
