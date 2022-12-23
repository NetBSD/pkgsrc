#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gerbera.sh,v 1.2 2022/12/23 21:44:20 gutteridge Exp $
#

# PROVIDE: gerbera
# REQUIRE: DAEMON

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="gerbera"
rcvar=$name
load_rc_config_var gerbera_username gerbera_username
command="@PREFIX@/bin/gerbera"
logfile="@VARBASE@/log/${name}.log"
pidfile="@PKG_HOME@/${name}.pid"
command_args="-u ${gerbera_username:-@GERBERA_USER@} -m @PKG_HOME@ -P ${pidfile} -l ${logfile} -c @PKG_SYSCONFDIR@/config.xml"

if [ -f @SYSCONFBASE@/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${gerbera_flags} ${command_args}
fi
