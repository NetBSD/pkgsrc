#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: kdc.sh,v 1.3 2005/10/26 15:12:45 jlam Exp $
#
# PROVIDE: kdc
# REQUIRE: NETWORKING
# BEFORE:  SERVERS

. /etc/rc.subr

name="kdc"
rcvar=$name
command="@PREFIX@/libexec/${name}"
command_args="--detach"
required_files="@PKG_SYSCONFDIR@/krb5.conf"

load_rc_config $name
run_rc_command "$1"
