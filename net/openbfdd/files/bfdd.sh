#
# $NetBSD: bfdd.sh,v 1.1 2025/01/15 13:28:29 manu Exp $
#

# PROVIDE: bfdd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

. /etc/rc.subr

name="bfdd"
required_files="@PKG_SYSCONFDIR@/bfdd.conf"
command="@PREFIX@/bin/bfdd-beacon"
command_args="--listen=127.0.0.1"
start_postcmd="bfdd_poststart"

bfdd_poststart() {
	@PREFIX@//bin/bfdd-control load @PKG_SYSCONFDIR@/bfdd.conf
}


load_rc_config $name
run_rc_command "$1"
