#!/bin/sh
#
# $NetBSD: nessusd.sh,v 1.1 2003/06/09 17:01:26 frueauf Exp $
#

# PROVIDE: nessusd
# REQUIRE: DAEMON

# To start nessusd at startup, copy this script to /etc/rc.d and set
# nessusd=YES in /etc/rc.conf.

. /etc/rc.subr

name="nessusd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
setup_cmd="nessusd_setup"
extra_commands="status setup"
command_args="-D"

nessusd_setup()
{
	echo "Dump of nessusd setup."
	@PREFIX@/sbin/nessusd -d
}

load_rc_config $name
run_rc_command "$1"
