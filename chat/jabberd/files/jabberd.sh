#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: jabberd.sh,v 1.2 2004/02/21 05:38:29 xtraeme Exp $
#

# PROVIDE: jabberd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="jabberd"
help_name="jabber"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/jabber.xml"
command_args="-B -c $required_files 2> /dev/null"
pidfile="@JABBERD_PIDDIR@/${help_name}.pid"
jabberd_user="@JABBERD_USER@"

load_rc_config $name
run_rc_command "$1"
