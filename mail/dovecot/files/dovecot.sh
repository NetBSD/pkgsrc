#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dovecot.sh,v 1.3 2008/06/22 17:41:23 ghen Exp $
#

# PROVIDE: dovecot
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="dovecot"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/$name.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
