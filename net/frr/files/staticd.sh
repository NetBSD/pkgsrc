#!/bin/sh
#
# staticd is part of the frr routing beast
#
# PROVIDE: staticd
# REQUIRE: zebra
##

PATH=/sbin:/bin:/usr/sbin:/usr/bin:@PREFIX@/sbin:@PREFIX@/bin
export PATH

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="staticd"
rcvar=$name
required_files="@PREFIX@/etc/frr/${name}.conf"
command="@PREFIX@/sbin/${name}"
command_args="-d"

socket_dir="@VARBASE@/run/frr"
pidfile="${socket_dir}/${name}.pid"

load_rc_config $name
run_rc_command "$1"
