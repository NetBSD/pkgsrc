#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mailgraph.sh,v 1.2 2005/11/14 12:34:57 kleink Exp $
#

# PROVIDE: mailgraph
# REQUIRE: DAEMON

. /etc/rc.subr

name="@PKGBASE@"
rcvar=$name
pidfile="@VARBASE@/run/${name}.pid"
command_interpreter="@PERL5@"
command="@PREFIX@/sbin/mailgraph"
command_args="-d"

load_rc_config $name
run_rc_command "$1"
