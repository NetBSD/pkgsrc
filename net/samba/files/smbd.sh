#!/bin/sh
#
# $NetBSD: smbd.sh,v 1.6 2001/11/21 16:44:18 jlam Exp $
#
# PROVIDE: smbd
# REQUIRE: DAEMON

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="smbd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	${command} ${smbd_flags} ${command_args}
else
	load_rc_config $name
	run_rc_command "$1"
fi
