#!/bin/sh
#
# $NetBSD: xdm_krb4.sh,v 1.1 2002/09/26 23:59:01 jlam Exp $
#

# PROVIDE: xdm-krb4
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="xdm-krb4"
rcvar="xdm_krb4"
pidfile="/var/run/xdm.pid"
extra_commands="reload"

if [ -x @PREFIX@/bin/${name} ]; then
	command="@PREFIX@/bin/${name}"
elif [ -x @PREFIX@/bin/xdm ]; then
	command="@X11BASE@/bin/xdm"
fi

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	eval [ -z "\$${rcvar}" ] && eval ${rcvar}=NO
	run_rc_command "$1"
else
	echo -n ' ${name}'
	${command} ${xdm_krb4_flags} ${command_args}
fi
