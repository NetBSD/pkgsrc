#! /bin/sh
#
# $NetBSD: cupsd.sh,v 1.8 2001/11/26 07:34:05 jlam Exp $
#
# Common UNIX Printing System daemon
#
# PROVIDE: cupsd
# REQUIRE: DAEMON

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="cupsd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/cups/${name}.conf"
extra_commands="reload"

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${cupsd_flags} ${command_args}
fi
