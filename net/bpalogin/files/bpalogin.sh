#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: bpalogin.sh,v 1.1 2002/11/21 10:02:57 grant Exp $
#
# bpalogin startup script
#
# PROVIDE: bpalogin
# REQUIRE: DAEMON dhcpd

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="bpalogin"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args="-c @PKG_SYSCONFDIR@/${name}.conf & sleep 1"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${bpalogin_flags} ${command_args}
fi
