#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cygwin_esd.sh,v 1.3 2011/10/07 22:37:03 shattered Exp $
#
# PROVIDE: cygwin_esd
# REQUIRE: DAEMON

name="cygwin_esd"
command="@PREFIX@/emul/cygwin/bin/esd.exe"
command_args="-tcp"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	${command} ${command_args} &
	exit
fi

. /etc/rc.subr

load_rc_config $name
command_args="${command_args} &"
run_rc_command "$1"
