#!/bin/sh
#
# $NetBSD: arlad.sh,v 1.4 2002/09/25 00:06:34 jlam Exp $
#
# PROVIDE: arlad
# REQUIRE: beforemountlkm

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="arlad"
rcvar=$name
command="@PREFIX@/libexec/${name}"
command_args="-z /dev/xfs0"
required_files="/dev/xfs0"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	eval [ -z "\$${rcvar}" ] && eval ${rcvar}=NO
	run_rc_command "$1"
else
	echo -n ' ${name}'
	${command} ${arlad_flags} ${command_args}
fi
