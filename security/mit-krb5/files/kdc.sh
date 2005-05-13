#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: kdc.sh,v 1.1.1.1.8.1 2005/05/13 10:08:52 salo Exp $
#
# PROVIDE: kdc
# REQUIRE: NETWORKING
# BEFORE:  SERVERS

. /etc/rc.subr

name="kdc"
rcvar=$name
command="@PREFIX@/sbin/krb5kdc"
required_files="@PKG_SYSCONFDIR@/krb5.conf @MIT_KRB5_STATEDIR@/krb5kdc/kdc.conf"

load_rc_config $name
run_rc_command "$1"
