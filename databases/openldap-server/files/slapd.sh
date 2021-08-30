#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: slapd.sh,v 1.2 2021/08/30 09:36:31 khorben Exp $
#
# OpenLDAP standalone LDAP daemon
#
# PROVIDE: slapd
# REQUIRE: DAEMON

. @SYSCONFBASE@/rc.subr

name="slapd"
rcvar=${name}
command="@PREFIX@/libexec/${name}"
required_files="@OPENLDAP_ETCDIR@/${name}.conf"
command_args="-u @SLAPD_USER@"

load_rc_config $name
run_rc_command "$1"
