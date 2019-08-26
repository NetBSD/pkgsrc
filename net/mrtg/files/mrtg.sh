#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mrtg.sh,v 1.1 2019/08/26 06:41:08 jnemeth Exp $
#
# PROVIDE: mrtg
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start Asterisk:
#
# mrtg=YES

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="mrtg"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_interpreter="@PERL5@"
pidfile=@PKG_SYSCONFDIR@/${name}.pid
required_files="@PKG_SYSCONFDIR@/mrtg.conf"
extra_commands="reload"
mrtg_flags="--daemon $required_files"

load_rc_config $name
run_rc_command "$1"
