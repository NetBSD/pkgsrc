#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ez-ipupdate.sh,v 1.1.1.1 2005/12/28 15:50:35 ghen Exp $
#
# PROVIDE: ez_ipupdate
# REQUIRE: DAEMON syslogd

. /etc/rc.subr

name="ez_ipupdate"
rcvar="${name}"
progname="ez-ipupdate"
command="@PREFIX@/bin/${progname}"
conf_file="@PKG_SYSCONFDIR@/${progname}.conf"
required_files="${conf_file}"
command_args="-d -c ${conf_file}"
sig_stop=QUIT
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
