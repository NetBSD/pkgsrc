#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: kadmind.sh,v 1.1 2005/10/26 15:12:45 jlam Exp $
#
# PROVIDE: kadmind
# REQUIRE: NETWORKING
# BEFORE:  SERVERS

. /etc/rc.subr

name="kadmind"
rcvar=$name
command="@PREFIX@/libexec/${name}"
command_args="& sleep 2"
required_files="@PKG_SYSCONFDIR@/krb5.conf"
required_vars="kdc"

load_rc_config $name
load_rc_config_var kdc kdc
run_rc_command "$1"
