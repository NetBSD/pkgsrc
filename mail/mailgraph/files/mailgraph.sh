#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mailgraph.sh,v 1.1.1.1 2004/12/31 21:36:59 kim Exp $
#

# PROVIDE: mailgraph
# REQUIRE: DAEMON

. /etc/rc.subr

name="@PKGBASE@"
rcvar=$name
pidfile="@VARBASE@/run/${name}.pid"
command_interpreter="@PERL@"
command="@PREFIX@/sbin/mailgraph"
command_args="-d"

load_rc_config $name
run_rc_command "$1"
