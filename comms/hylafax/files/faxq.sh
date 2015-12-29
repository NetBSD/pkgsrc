#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: faxq.sh,v 1.1 2015/12/29 00:05:54 dholland Exp $

# PROVIDE: faxq
# REQUIRE: DAEMON
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name=faxq
rcvar=$name
command=@PREFIX@/sbin/faxq
command_args=
#pidfile=@VARBASE@/run/faxq.pid
required_files=@VARBASE@/spool/hylafax/etc/config

load_rc_config $name
run_rc_command "$1"

	