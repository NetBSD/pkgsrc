#!/bin/sh
#
# $NetBSD: nmbd.sh,v 1.1.1.1 2001/08/03 13:24:36 jlam Exp $
#
# PROVIDE: nmbd
# REQUIRE: DAEMON

name="nmbd"
command="@PREFIX@/sbin/${name}"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${nmbd_flags}

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
