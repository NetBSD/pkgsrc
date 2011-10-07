#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rtspd.sh,v 1.4 2011/10/07 22:37:04 shattered Exp $
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
