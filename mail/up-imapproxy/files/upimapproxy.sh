#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upimapproxy.sh,v 1.1.1.1 2006/05/08 21:58:31 adrianp Exp $
#

# PROVIDE: upimapproxy
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="upimapproxy"
rcvar=$name
command="@PREFIX@/sbin/in.imapproxyd"
required_files="@PKG_SYSCONFDIR@/imapproxy.conf"

load_rc_config $name
run_rc_command "$1"
