#!/bin/sh
#
# $NetBSD: nmbd.sh,v 1.5 2001/11/21 16:44:18 jlam Exp $
#
# PROVIDE: nmbd
# REQUIRE: DAEMON

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="nmbd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}

reload_cmd=":"			# avoid dumping debug output on SIGHUP

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	${command} ${nmbd_flags} ${command_args}
else
	load_rc_config $name
	run_rc_command "$1"
fi
