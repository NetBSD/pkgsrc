#!/bin/sh
#
# $NetBSD: moss.sh,v 1.1.1.1 2004/08/10 06:48:21 minskim Exp $
#

# PROVIDE: moss
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="moss"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_interpreter="@INTERPRETER@"
pidfile="/var/run/moss.pid"
required_files="@PREFIX@/etc/moss.conf"
command_args="-c ${required_files}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${command_args}
fi
