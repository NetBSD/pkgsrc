#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gerbera.sh,v 1.3 2024/07/10 06:17:17 wiz Exp $
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
command_args="-d -u ${gerbera_username:-@GERBERA_USER@} -m @PKG_HOME@ -P ${pidfile} -l ${logfile} -c @PKG_SYSCONFDIR@/config.xml"

if [ -f @SYSCONFBASE@/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${gerbera_flags} ${command_args}
fi
