#!/bin/sh
#
# $NetBSD: rtspd.sh,v 1.3 2001/02/04 16:55:47 tron Exp $
#
# PROVIDE: rtspd
# REQUIRE: DAEMON

name="rtspd"
command="@PREFIX@/sbin/${name}"
command_args="-u nobody"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	exec ${command} ${command_args}
fi

. /etc/rc.subr

load_rc_config $name
run_rc_command "$1"
