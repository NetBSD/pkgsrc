#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: postgrey.sh,v 1.3 2019/09/07 17:13:56 kim Exp $
#

# PROVIDE: postgrey
# BEFORE: mail
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="@PKGBASE@"
rcvar=$name
pidfile="@VARBASE@/run/${name}/${name}.pid"
command_interpreter="@PERL@"
command="@PREFIX@/sbin/postgrey"
command_args="-d --pidfile=${pidfile}"
required_files="
 @PKG_SYSCONFDIR@/postgrey_whitelist_clients
 @PKG_SYSCONFDIR@/postgrey_whitelist_recipients
"
@PKGBASE@_flags=${@PKGBASE@_flags-"-i 2525"}
extra_commands="reload"
start_precmd="postgrey_precmd"

postgrey_precmd()
{
	if [ ! -d "@VARBASE@/run/${name}" ]; then
		@MKDIR@ "@VARBASE@/run/${name}"
		@CHMOD@ 775 "@VARBASE@/run/${name}"
		@CHOWN@ @POSTGREY_USER@:@POSTGREY_GROUP@ "@VARBASE@/run/${name}"
	fi
}

load_rc_config $name
run_rc_command "$1"
