#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: imapproxy.sh,v 1.2 2011/10/07 22:37:03 shattered Exp $
#

# PROVIDE: imapproxy
# REQUIRE: DAEMON
# BEFORE:  LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="imapproxy"
rcvar=$name
command="@PREFIX@/sbin/in.imapproxyd"
required_files="@PKG_SYSCONFDIR@/imapproxy.conf"

load_rc_config $name
run_rc_command "$1"
