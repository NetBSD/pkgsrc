#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upslog.sh,v 1.6 2004/02/15 13:14:25 lukem Exp $
#
# PROVIDE: upslog
# REQUIRE: upsd
#
# You will need to set some variables in /etc/rc.conf to start upslog
# properly, e.g.
#
# upslog=YES
# upslog_flags="smartups@localhost /var/log/ups 60"
#
# Please refer to upslog(8) for more information about the arguments to pass
# to upslog.

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="upslog"
rcvar="${name}"
command="@PREFIX@/bin/${name}"
pidfile="@NUT_STATEDIR@/${name}.pid"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${upslog_flags} ${command_args}
fi
