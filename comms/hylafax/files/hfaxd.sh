#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: hfaxd.sh,v 1.1 2015/12/29 00:05:54 dholland Exp $

# PROVIDE: hfaxd
# REQUIRE: DAEMON
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name=hfaxd
rcvar=$name
command=@PREFIX@/libexec/hfaxd
command_args="-i 4559 -o 4557 -s 444"
#pidfile=@VARBASE@/run/hfaxd.pid
required_files=@VARBASE@/spool/hylafax/etc/config

load_rc_config $name
run_rc_command "$1"

	