#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: slurpd.sh,v 1.3 2005/10/26 15:08:13 jlam Exp $
#
# OpenLDAP LDAP database replication daemon
#
# PROVIDE: slurpd
# REQUIRE: slapd

. /etc/rc.subr

name="slurpd"
rcvar=${name}
command="@PREFIX@/libexec/${name}"
required_files="@OPENLDAP_ETCDIR@/slapd.conf"
required_vars="slapd"

load_rc_config $name
run_rc_command "$1"
