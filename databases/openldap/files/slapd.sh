#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: slapd.sh,v 1.7 2005/10/26 15:08:13 jlam Exp $
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

load_rc_config $name
run_rc_command "$1"
