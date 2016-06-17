#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: slapd.sh,v 1.1 2016/06/17 13:56:53 jperkin Exp $
#
# OpenLDAP standalone LDAP daemon
#
# PROVIDE: slapd
# REQUIRE: DAEMON

. /etc/rc.subr

name="slapd"
rcvar=${name}
command="@PREFIX@/libexec/${name}"
required_files="@OPENLDAP_ETCDIR@/${name}.conf"
command_args="-u @SLAPD_USER@"

load_rc_config $name
run_rc_command "$1"
