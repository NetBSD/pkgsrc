#! /bin/sh
#
# $NetBSD: slpd.sh,v 1.6 2002/09/20 01:43:22 grant Exp $
#
# Service Location Protocol daemon
#
# PROVIDE: slpd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="slpd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="/etc/slp.conf"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	eval [ -z "\$${rcvar}" ] && eval ${rcvar}=NO
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${slpd_flags} ${command_args}
fi
