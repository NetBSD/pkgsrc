#!/bin/sh
#
# $NetBSD: nmbd.sh,v 1.1 2001/02/04 15:29:58 tron Exp $
#
# PROVIDE: nmbd
# REQUIRE: DAEMON

name="nmbd"
command="@PREFIX@/sbin/${name}"
command_args="-D"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	exec ${command} ${command_args}
fi

. /etc/rc.subr

pidfile="/var/run/samba/${name}.pid"
required_files="/etc/samba/smb.conf"

load_rc_config $name
run_rc_command "$1"
