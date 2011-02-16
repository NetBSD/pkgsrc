#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: postgrey.sh,v 1.2 2011/02/16 19:37:50 shattered Exp $
#

# PROVIDE: postgrey
# BEFORE: mail
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="@PKGBASE@"
rcvar=$name
pidfile="@VARBASE@/run/${name}.pid"
command_interpreter="@PERL@"
command="@PREFIX@/sbin/postgrey"
command_args="-d --pidfile=${pidfile}"
required_files="
 @PKG_SYSCONFDIR@/postgrey_whitelist_clients
 @PKG_SYSCONFDIR@/postgrey_whitelist_recipients
"
@PKGBASE@_flags=${@PKGBASE@_flags-"-i 2525"}
extra_commands="reload"
stop_postcmd='rm -f $pidfile'

load_rc_config $name
run_rc_command "$1"
