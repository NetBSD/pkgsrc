#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sasl_pwcheck.sh,v 1.10 2002/09/20 02:02:00 grant Exp $
#
# The pwcheck daemon allows UNIX password authentication with Cyrus SASL.
#
# PROVIDE: sasl_pwcheck
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="sasl_pwcheck"
rcvar="${name}"
command="@PREFIX@/sbin/pwcheck"
command_args="& sleep 2"
start_precmd=sasl_pwcheck_precmd

sasl_pwcheck_precmd()
{
	if [ ! -d @SASLSOCKETDIR@ ]
	then
		@MKDIR@ @SASLSOCKETDIR@
		@CHMOD@ 0700 @SASLSOCKETDIR@
		@CHOWN@ @CYRUS_USER@ @SASLSOCKETDIR@
	fi
}

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	eval ${start_precmd}
	${command} ${sasl_pwcheck_flags} ${command_args}
fi
