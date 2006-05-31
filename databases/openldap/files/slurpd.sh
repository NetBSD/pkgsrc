#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: slurpd.sh,v 1.4 2006/05/31 18:17:49 ghen Exp $
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
slurpd_user="@SLURPD_USER@"

load_rc_config $name
run_rc_command "$1"
