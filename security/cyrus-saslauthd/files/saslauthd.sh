#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: saslauthd.sh,v 1.4 2022/05/10 03:34:16 khorben Exp $
#
# The saslauthd daemon allows cleartext UNIX password authentication via
# several authentication mechanisms with Cyrus SASL.
#
# PROVIDE: saslauthd
# REQUIRE: DAEMON
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start saslauthd:
#
# saslauthd=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="saslauthd"
rcvar="${name}"
command="@PREFIX@/sbin/saslauthd"
pidfile="@SASLSOCKETDIR@/${name}.pid"
start_precmd="saslauthd_precmd"

# Default to authenticating against local password database.
: ${saslauthd_flags="-a getpwent"}

saslauthd_precmd()
{
        if [ ! -d @SASLSOCKETDIR@ ]; then
                @MKDIR@ @SASLSOCKETDIR@
                @CHMOD@ 0755 @SASLSOCKETDIR@
                @CHOWN@ @ROOT_USER@ @SASLSOCKETDIR@
        fi
}

if [ -f @SYSCONFBASE@/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${saslauthd_flags} ${command_args}
fi
