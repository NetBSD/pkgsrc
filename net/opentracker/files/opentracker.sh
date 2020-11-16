#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: opentracker.sh,v 1.1 2020/11/16 08:41:25 wiz Exp $
#

# PROVIDE: opentracker
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="vsftpd"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="&"

load_rc_config $name
run_rc_command "$1"
