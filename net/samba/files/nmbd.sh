#!/bin/sh
#
# $NetBSD: nmbd.sh,v 1.2 2001/05/13 00:44:50 wiz Exp $
#
# PROVIDE: nmbd
# REQUIRE: DAEMON

name="nmbd"
command="@PREFIX@/sbin/${name}"
nmbd_flags="-D"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	exec ${command} ${nmbd_flags} ${command_args}
fi

. /etc/rc.subr

pidfile="/var/run/samba/${name}.pid"
required_files="/etc/samba/smb.conf"

load_rc_config $name
run_rc_command "$1"
