#!/bin/sh
#
# $NetBSD: samba.sh,v 1.1 2001/08/22 15:42:19 jlam Exp $
#
# PROVIDE: samba
# REQUIRE: DAEMON
#
# nmbd may require DNS to resolve NetBIOS hostnames, and smbd may be acting as
# a Backup Domain Controller and may need the network to be up, so simply
# require DAEMON above.
#
# To use this script, copy to /etc/rc.d and set samba=YES in /etc/rc.conf.
# You may also set nmbd_flags and smbd_flags to any additional options you
# wish to pass to the Samba daemons.

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

arg="$1"
rcvar="samba"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}

name="nmbd"
command="@PREFIX@/sbin/${name}"
reload_cmd=":"			# avoid dumping debug output on SIGHUP

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	${command} ${nmbd_flags} ${command_args}
else
	load_rc_config $name
	run_rc_command "$arg"
fi

name="smbd"
command="@PREFIX@/sbin/${name}"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	${command} ${smbd_flags} ${command_args}
else
	load_rc_config $name
	run_rc_command "$1"
fi
