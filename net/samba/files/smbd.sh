#!/bin/sh
#
# $NetBSD: smbd.sh,v 1.1 2001/02/04 15:29:59 tron Exp $
#
# PROVIDE: smbd
# REQUIRE: nmbd

name="smbd"
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
