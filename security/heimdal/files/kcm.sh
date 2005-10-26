#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: kcm.sh,v 1.1 2005/10/26 15:12:45 jlam Exp $
#
# PROVIDE: kcm
# REQUIRE: NETWORKING
# BEFORE:  SERVERS

. /etc/rc.subr

name="kcm"
rcvar=$name
command="@PREFIX@/libexec/${name}"
command_args="--detach"
required_files="@PKG_SYSCONFDIR@/krb5.conf"

load_rc_config $name
run_rc_command "$1"
