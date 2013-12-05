#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: opendmarc.sh,v 1.1 2013/12/05 16:00:19 pettai Exp $
#
# PROVIDE: opendmarc
# REQUIRE: DAEMON
# BEFORE: mail

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="opendmarc"
rcvar=$name
command="@PREFIX@/sbin/opendmarc"
pidfile="@VARBASE@/run/opendmarc/${name}.pid"
command_args="-P ${pidfile} -c @PKG_SYSCONFDIR@/opendmarc.conf" 
required_files="@PKG_SYSCONFDIR@/opendmarc.conf"
start_precmd="opendmarc_precmd"

opendmarc_precmd()
{
	if [ ! -d @VARBASE@/run/opendmarc ]; then
		@MKDIR@ @VARBASE@/run/opendmarc
		@CHMOD@ 0750 @VARBASE@/run/opendmarc
	fi

	if [ -f @VARBASE@/run/opendmarc/${name}.sock ]; then
		@RM@ -f @VARBASE@/run/opendmarc/${name}.sock
	fi
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${opendmarc_flags} ${command_args}
fi
