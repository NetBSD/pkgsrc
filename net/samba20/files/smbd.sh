#!/bin/sh
#
# $NetBSD: smbd.sh,v 1.1.1.1 2001/08/03 13:24:37 jlam Exp $
#
# PROVIDE: smbd
# REQUIRE: nmbd

name="smbd"
command="@PREFIX@/sbin/${name}"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${smbd_flags}

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
