#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cupsd.sh,v 1.14 2002/10/31 23:33:12 jlam Exp $
#
# Common UNIX Printing System daemon
#
# PROVIDE: cupsd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="cupsd"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args="& sleep 2"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
extra_commands="reload"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${cupsd_flags} ${command_args}
fi
