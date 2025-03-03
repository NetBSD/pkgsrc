#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: spampd.sh,v 1.1 2025/03/03 14:51:59 jakllsch Exp $
#

# PROVIDE: spampd
# BEFORE: mail
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="@PKGBASE@"
rcvar=$name
pidfile="@VARBASE@/run/${name}/${name}.pid"
command_interpreter="@PERL@"
command="@PREFIX@/sbin/@PKGBASE@"
command_args="-p ${pidfile} -u @SPAMPD_USER@ -g @SPAMPD_GROUP@"
extra_commands="reload"
start_precmd="spampd_prestart"

spampd_prestart()
{
	if [ ! -d "@VARBASE@/run/${name}" ]; then
		@MKDIR@ "@VARBASE@/run/${name}"
		@CHMOD@ 775 "@VARBASE@/run/${name}"
		@CHOWN@ @SPAMPD_USER@:@SPAMPD_GROUP@ "@VARBASE@/run/${name}"
	fi
}

load_rc_config $name
run_rc_command "$1"
