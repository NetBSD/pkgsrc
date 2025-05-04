#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dropbear.sh,v 1.1 2025/05/04 13:17:38 nia Exp $
#
# PROVIDE: dropbear
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="dropbear"
rcvar=$name
command="@PREFIX@/sbin/dropbear"
command_args="${command_args} -R"
command_args="${command_args} -P @VARBASE@/run/dropbear.pid"
pidfile="@VARBASE@/run/dropbear.pid"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${dropbear_flags} ${command_args}
fi
