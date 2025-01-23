#!/bin/sh
#
# $NetBSD: turnserver.sh,v 1.4 2025/01/23 17:21:26 gdt Exp $
#
# PROVIDE: turnserver
# REQUIRE: LOGIN
# KEYWORD: shutdown
#
# Add the following lines to /etc/rc.conf.local or /etc/rc.conf
# to enable this service:
#
# turnserver (bool):		Set to NO by default.
#				Set it to YES to enable turnserver.
# turnserver_config (path):	Set to @PREFIX@/etc/turnserver.conf
#				by default.

if [ -f @SYSCONFBASE@/rc.subr ]; then
  . @SYSCONFBASE@/rc.subr
fi

name="turnserver"
rcvar=${name}

if [ -f @SYSCONFBASE@/rc.subr -a -d @SYSCONFBASE@/rc.d -a -f @SYSCONFBASE@/rc.d/DAEMON ]; then
	load_rc_config $name
elif [ -f @SYSCONFBASE@/rc.conf ]; then
	. @SYSCONFBASE@/rc.conf
fi

: ${turnserver:=no}
: ${turnserver_config=@PKG_SYSCONFDIR@/turnserver.conf}
: ${coturn_user:=@COTURN_USER@}
: ${coturn_group:=@COTURN_GROUP@}

pidfile="@VARBASE@/run/${name}.pid"
command="@PREFIX@/bin/${name}"
command_args="--daemon --proc-user ${coturn_user} --proc-group ${coturn_user} -c ${turnserver_config} --pidfile ${pidfile}"
required_files=${turnserver_config}

if [ -f @SYSCONFBASE@/rc.subr -a -d @SYSCONFBASE@/rc.d -a -f @SYSCONFBASE@/rc.d/DAEMON ]; then
	run_rc_command "$1"
else
	case "$1" in
	stop)
		if [ -r "${pidfile}" ]; then
			@ECHO@ "Stopping ${name}."
			kill `@CAT@ ${pidfile}`
		fi
		;;
	*)
		${command} ${command_args}
		;;
	esac
fi
