#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: icecast.sh,v 1.4 2004/01/12 05:56:04 xtraeme Exp $
#

# PROVIDE: icecast
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="icecast"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="-b -c @PKG_SYSCONFDIR@/$name.xml >/dev/null 2>&1"
required_files="@PKG_SYSCONFDIR@/$name.xml"

load_rc_config $name
run_rc_command "$1"
