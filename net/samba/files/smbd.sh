#!/bin/sh
#
# $NetBSD: smbd.sh,v 1.2 2001/05/13 00:44:50 wiz Exp $
#
# PROVIDE: smbd
# REQUIRE: nmbd

name="smbd"
command="@PREFIX@/sbin/${name}"
smbd_flags="-D"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	exec ${command} ${smbd_flags} ${command_args}
fi

. /etc/rc.subr

pidfile="/var/run/samba/${name}.pid"
required_files="/etc/samba/smb.conf"

load_rc_config $name
run_rc_command "$1"
