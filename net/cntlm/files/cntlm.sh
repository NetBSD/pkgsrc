#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cntlm.sh,v 1.1.1.1 2009/10/30 19:55:30 jym Exp $
#
# PROVIDE: cntlm
# REQUIRE: DAEMON
#
# You will need to set some variables in /etc/rc.conf to start cntlm:
#
# cntlm=YES
#
# The following variables are optional:
#
# cntlm_flags="" # Additional flags to pass to cntlm
#
# "cntlm_flags" contains options for the cntlm daemon. See cntlm(1) for
# possible options.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="cntlm"
rcvar=${name}

cntlm_config="@PKG_SYSCONFDIR@/${name}.conf"
cntlm_user="@CNTLM_USER@"
pidfile="@VARBASE@/run/${name}.pid"

command="@PREFIX@/bin/${name}"
command_args="-U $cntlm_user -P $pidfile -c $cntlm_config "
required_files="$cntlm_config"

start_precmd="cntlm_prestartcmd"
stop_postcmd="cntlm_poststopcmd"

cntlm_prestartcmd() {
	touch $pidfile
	chown $cntlm_user $pidfile
}

cntlm_poststopcmd() {
	if [ -f $pidfile ]; then
		rm -f $pidfile
	fi
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n ' ${name}'
	${command} ${cntlm_flags} ${command_args}
fi
