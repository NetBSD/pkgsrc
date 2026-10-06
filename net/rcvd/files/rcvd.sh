#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rcvd.sh,v 1.1 2026/10/06 11:23:17 drixter Exp $
#
# PROVIDE: rcvd
# REQUIRE: DAEMON SERVERS
# KEYWORD: shutdown
#
# rcvd: privacy-first encrypted DNS engine.
#
# The REQUIRE line above matches the pkgsrc convention for a DNS forwarder
# (as used by dnsmasq and unbound): rcvd starts in the normal daemon batch.
# If you run rcvd AS THE SYSTEM RESOLVER, so that other local daemons resolve
# names through it, use the named(8)-style ordering instead so rcvd comes up
# first (rcvd bootstraps over pinned IPs, needing no cleartext DNS):
#   # REQUIRE: NETWORKING
#   # BEFORE:  DAEMON
#
# To enable, add the following to /etc/rc.conf:
#   rcvd=YES
#
# Optional overrides (defaults shown):
#   rcvd_conf="@PKG_SYSCONFDIR@/rcvd/rcvd.toml"
#   rcvd_user="rcvd"
#   rcvd_flags="-config ${rcvd_conf}"

. /etc/rc.subr

name="rcvd"
rcvar=${name}
command="@PREFIX@/bin/rcvd"
: ${rcvd_conf:="@PKG_SYSCONFDIR@/rcvd/rcvd.toml"}
: ${rcvd_user:="rcvd"}
: ${rcvd_flags:="-config ${rcvd_conf}"}

command_args="&"
required_files="${rcvd_conf}"

load_rc_config $name
run_rc_command "$1"
