#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: saslauthd.sh,v 1.4 2003/11/21 10:41:56 jlam Exp $
#
# The saslauthd daemon allows cleartext UNIX password authentication via
# several authentication mechanisms with Cyrus SASL.
#
# PROVIDE: saslauthd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="saslauthd"
rcvar="${name}"
command="@PREFIX@/sbin/saslauthd"
start_precmd="saslauthd_precmd"

# Default to authenticating against local password database.
if [ -z "${saslauthd_flags}" ]
then
	saslauthd_flags="-a getpwent"
fi

saslauthd_precmd()
{
        if [ ! -d @SASLSOCKETDIR@ ]
        then
                @MKDIR@ @SASLSOCKETDIR@
                @CHMOD@ 0755 @SASLSOCKETDIR@
                @CHOWN@ @ROOT_USER@ @SASLSOCKETDIR@
        fi
}

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${saslauthd_flags} ${command_args}
fi
