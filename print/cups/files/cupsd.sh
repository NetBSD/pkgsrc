#! /bin/sh
#
# $NetBSD: cupsd.sh,v 1.6 2001/11/21 15:35:09 jlam Exp $
#
# Common UNIX Printing System daemon
#
# PROVIDE: cupsd
# REQUIRE: DAEMON

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="cupsd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@CONFDIR@/cups/${name}.conf"
extra_commands="reload"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n " ${name}"
	exec ${command} ${cupsd_flags} ${command_args}
fi

load_rc_config $name
run_rc_command "$1"
