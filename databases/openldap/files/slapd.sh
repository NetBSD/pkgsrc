#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: slapd.sh,v 1.6 2004/07/24 03:32:24 jlam Exp $
#
# OpenLDAP standalone LDAP daemon
#
# PROVIDE: slapd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="slapd"
rcvar=${name}
command="@PREFIX@/libexec/${name}"
required_files="@OPENLDAP_ETCDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${slapd_flags} ${command_args}
fi
