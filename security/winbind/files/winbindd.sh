#!/bin/sh
#
# $NetBSD: winbindd.sh,v 1.1.1.1 2002/07/29 04:19:00 jlam Exp $
#
# PROVIDE: winbindd
# REQUIRE: nmbd

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="winbindd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_vars="nmbd"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	${command} ${winbindd_flags}
fi
