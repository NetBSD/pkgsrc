#!/bin/sh
#
# $NetBSD: smbd.sh,v 1.2 2001/08/20 14:01:46 jlam Exp $
#
# PROVIDE: smbd
# REQUIRE: nmbd

name="smbd"
command="@PREFIX@/sbin/${name}"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${smbd_flags}
extra_commands="reload"

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
