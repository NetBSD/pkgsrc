#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: policyd.sh,v 1.1.1.1 2007/08/07 12:34:56 ghen Exp $

# PROVIDE: policyd
# BEFORE: mail
# AFTER: mysqld
# REQUIRE: DAEMON

. /etc/rc.subr

name="policyd"
rcvar=$name
command="@BINDIR@/${name}"
conf_file="@PKG_SYSCONFDIR@/$name.conf"
required_files="${conf_file}"
pidfile="@VARBASE@/run/${name}.pid"
command_args="-c ${conf_file}"

load_rc_config $name
run_rc_command "$1"
