#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mopherd.sh,v 1.1 2014/12/01 13:58:15 gdt Exp $
#
# PROVIDE: mopherd
# REQUIRE: DAEMON
# BEFORE:  mail
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name=mopherd
rcvar=mopherd
pidfile=@MOPHER_RUN@/mopherd.pid
start_precmd=mopherd_precmd
command=@PREFIX@/sbin/mopherd
command_args="-p $pidfile"

mopherd_precmd()
{
	@INSTALL@ -d -o @MOPHER_USER@ -g @MOPHER_GROUP@ @MOPHER_RUN@
}

load_rc_config mopherd
run_rc_command "$1"
