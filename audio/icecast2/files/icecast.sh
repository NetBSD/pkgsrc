#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: icecast.sh,v 1.1.1.1 2004/01/08 19:39:42 xtraeme Exp $
#

# PROVIDE: icecast
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="icecast"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="-b -c @PKG_SYSCONFDIR@/$name.xml 1>2& >/dev/null"
required_files="@PKG_SYSCONFDIR@/$name.xml"

load_rc_config $name
run_rc_command "$1"
