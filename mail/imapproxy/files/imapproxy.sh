#!/bin/sh
#
# $NetBSD: imapproxy.sh,v 1.1 2010/03/22 08:10:36 manu Exp $
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
