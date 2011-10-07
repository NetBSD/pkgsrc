#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mydns.sh,v 1.2 2011/10/07 22:37:04 shattered Exp $
#
# PROVIDE: mydns
# REQUIRE: SERVERS
# BEFORE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="mydns"
rcvar=$name
command="@PREFIX@/sbin/mydns"
command_args="-b"
required_files="@PKG_SYSCONFDIR@/mydns.conf"
extra_commands="reload"
reload_sig="HUP"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}$"
	${command} ${command_args} ${mydns_flags}
fi
