#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: kadmind.sh,v 1.3 2018/06/15 20:46:01 tez Exp $
#
# PROVIDE: kadmind
# REQUIRE: kdc
# BEFORE:  SERVERS

. /etc/rc.subr

name="kadmind"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/krb5.conf @MIT_KRB5_STATEDIR@/krb5kdc/kdc.conf"

load_rc_config $name
run_rc_command "$1"
