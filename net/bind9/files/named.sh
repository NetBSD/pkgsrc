#!/bin/sh
#
# $NetBSD: named.sh,v 1.2 2002/09/23 14:40:52 grant Exp $
#
# PROVIDE: named
# REQUIRE: SERVERS

. /etc/rc.subr

name="named"
rcvar=${name}9
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

extra_commands="reload"

load_rc_config ${name}9		# check /etc/rc.conf.d/named9

named_precmd()
{
	# Die if $named is also set (i.e. the system's named is not disabled
	if checkyesno named ; then
		warn \
	"disable 'named' when setting 'named9'!"
		return 1
	fi
}
start_precmd="named_precmd"

run_rc_command "$1"
