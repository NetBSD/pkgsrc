#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: skkserv.sh,v 1.3 2006/07/05 07:09:33 jlam Exp $
#
# PROVIDE: skkserv
# REQUIRE: DAEMON

. /etc/rc.subr
 
name="skkserv"
rcvar=$name
command="@PREFIX@/libexec/${name}"

load_rc_config $name
run_rc_command "$1"
