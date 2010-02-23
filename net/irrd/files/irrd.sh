#!/bin/sh
#
# PROVIDE: irrd
# REQUIRE: DAEMON

name="irrd"

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
else
	if [ -f @PREFIX@/etc/rc.subr ]; then
		. @PREFIX@/etc/rc.subr
	fi
fi

: ${irrd_conf:="@PKG_SYSCONFDIR@/irrd.conf"}

rcvar=${name}
required_files="${irrd_conf}"
command="@PREFIX@/sbin/irrd"
command_args="-f ${irrd_conf} -l @IRRD_USER@ -g @IRRD_GROUP@"

load_rc_config $name
run_rc_command "$1"
