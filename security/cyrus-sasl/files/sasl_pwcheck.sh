#! /bin/sh
#
# $NetBSD: sasl_pwcheck.sh,v 1.3 2001/11/26 07:34:05 jlam Exp $
#
# The pwcheck daemon allows UNIX password authentication with Cyrus SASL.
#
# PROVIDE: sasl_pwcheck
# REQUIRE: DAEMON

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="sasl_pwcheck"
rcvar="${name}"
command="@PREFIX@/sbin/pwcheck"
command_args="& sleep 2"
extra_commands="dbinit"

sasldb=@PKG_SYSCONFDIR@/sasldb.db

sasl_pwcheck_dbinit()
{
	(
	saslpasswd=@PREFIX@/sbin/saslpasswd
	umask 002
	if [ -e ${sasldb} ]
	then
		@ECHO@ "You already have an existing SASL password database"
		@ECHO@ "Skipping empty database generation"
	else
		@ECHO@ password | ${saslpasswd} -p user
		${saslpasswd} -d user
		@CHOWN@ @PKG_USER@ ${sasldb}
		@CHMOD@ 0600 ${sasldb}
	fi
	)
}

sasl_pwcheck_precmd()
{
	if [ ! -e ${sasldb} ]
	then
		@RCD_SCRIPTS_DIR@/sasl_pwcheck dbinit
	fi
}

dbinit_cmd=sasl_pwcheck_dbinit
start_precmd=sasl_pwcheck_precmd

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	start_precmd
	${command} ${sasl_pwcheck_flags} ${command_args}
fi
