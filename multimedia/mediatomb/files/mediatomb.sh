#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mediatomb.sh,v 1.4 2021/08/30 21:49:00 khorben Exp $
#
# PROVIDE: mediatomb
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in @PKG_SYSCONFDIR@/rc.conf to start mediatomb:
#
# mediatomb=YES

if [ -f @SYSCONFBASE@/rc.subr ]; then
	. @SYSCONFBASE@/rc.subr
	load_rc_config_var mediatomb_username mediatomb_username
	load_rc_config_var mediatomb_groupname mediatomb_groupname
fi

name="mediatomb"
rcvar=$name
command="@PREFIX@/bin/mediatomb"
logfile="@VARBASE@/log/${name}.log"
pidfile="@PKG_HOME@/${name}.pid"
command_args="-d -u ${mediatomb_username:-@MEDIATOMB_USER@} -g ${mediatomb_groupname:-@MEDIATOMB_USER@} -m @PKG_HOME@ -P ${pidfile} -l ${logfile} -c @PKG_SYSCONFDIR@/config.xml"
extra_commands="reload"

if [ -f @SYSCONFBASE@/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${mediatomb_flags} ${command_args}
fi
