#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: opendkim.sh,v 1.3 2011/06/17 13:49:35 pettai Exp $
#
# PROVIDE: opendkim
# REQUIRE: DAEMON
# BEFORE: mail

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="opendkim"
rcvar=$name
command="@PREFIX@/sbin/opendkim"
pidfile="@VARBASE@/run/opendkim/${name}.pid"
command_args="-P ${pidfile} -l -x @PKG_SYSCONFDIR@/opendkim.conf -u @DKIM_USER@:@DKIM_GROUP@"
required_files="@PKG_SYSCONFDIR@/opendkim.conf"
start_precmd="opendkim_precmd"

opendkim_precmd()
{
	if [ ! -d @VARBASE@/run/opendkim ]; then
		@MKDIR@ @VARBASE@/run/opendkim
		@CHMOD@ 0750 @VARBASE@/run/opendkim
		@CHOWN@ @DKIM_USER@:@DKIM_GROUP@ @VARBASE@/run/opendkim
	fi

	if [ -f @VARBASE@/run/opendkim/${name}.sock ]; then
		@RM@ -f @VARBASE@/run/opendkim/${name}.sock
	fi
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${opendkim_flags} ${command_args}
fi
