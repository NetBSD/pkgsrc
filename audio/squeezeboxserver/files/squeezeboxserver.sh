#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: squeezeboxserver.sh,v 1.1.1.1 2010/07/05 00:54:46 cube Exp $
#
# PROVIDE: squeezeboxserver
# REQUIRE: DAEMON
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="squeezeboxserver"
rcvar=${name}
pidfile="@SBS_VARDIR@/${name}.pid"
command="@SBS_LIBDIR@/slimserver.pl"
command_args="--daemon --user @SBS_USER@ --group @SBS_GROUP@ --pidfile ${pidfile}"
command_interpreter="@PERL5@"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${squeezeboxserver_flags} ${command_args}
fi
