#! /bin/sh
#
# $NetBSD: sasl_pwcheck.sh,v 1.6 2002/01/31 21:41:18 jlam Exp $
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

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${sasl_pwcheck_flags} ${command_args}
fi
