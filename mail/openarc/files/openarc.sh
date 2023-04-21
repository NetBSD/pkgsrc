#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: openarc.sh,v 1.1 2023/04/21 00:49:56 manu Exp $
#
# PROVIDE: openarc
# REQUIRE: DAEMON
# BEFORE: mail

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="openarc"
rcvar=$name
command="@PREFIX@/sbin/openarc"
pidfile="@VARBASE@/run/openarc/${name}.pid"
command_args="-P ${pidfile} -c @PKG_SYSCONFDIR@/openarc.conf" 
required_files="@PKG_SYSCONFDIR@/openarc.conf"
start_precmd="openarc_precmd"

openarc_precmd()
{
        if [ ! -d @VARBASE@/run/openarc ]; then
                @MKDIR@ @VARBASE@/run/openarc
                @CHMOD@ 0750 @VARBASE@/run/openarc
        fi

	if [ -f @VARBASE@/run/openarc/${name}.sock ]; then
		@RM@ -f @VARBASE@/run/openarc/${name}.sock
	fi
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${openarc_flags} ${command_args}
fi
