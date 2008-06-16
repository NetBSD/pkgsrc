#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: atheme.sh,v 1.1.1.1 2008/06/16 10:38:27 adrianp Exp $
#
# PROVIDE: atheme
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="atheme"
rcvar=${name}
command="@PREFIX@/bin/${name}-services"
required_files="@PKG_SYSCONFDIR@/atheme.conf"
pidfile="@VARBASE@/run/atheme/atheme.pid"
atheme_user="@ATHEME_USER@"
atheme_group="@ATHEME_GROUP@"
# command_args="-l @VARBASE@/log/atheme/atheme.log -p ${pidfile}"
start_precmd="atheme_precmd"

atheme_precmd()
{
	if [ ! -d @VARBASE@/run/atheme ]; then
		@MKDIR@ @VARBASE@/run/atheme
		@CHMOD@ 0750 @VARBASE@/run/atheme
		@CHOWN@ @ATHEME_USER@:@ATHEME_GROUP@ @VARBASE@/run/atheme
	fi

	if [ ! -d @VARBASE@/log/atheme ]; then
		@MKDIR@ @VARBASE@/log/atheme
		@CHMOD@ 0750 @VARBASE@/log/atheme
		@CHOWN@ @ATHEME_USER@:@ATHEME_GROUP@ @VARBASE@/log/atheme
	fi

	if [ ! -d @VARBASE@/atheme ]; then
		@MKDIR@ @VARBASE@/atheme
		@CHMOD@ 0750 @VARBASE@/atheme
		@CHOWN@ @ATHEME_USER@:@ATHEME_GROUP@ @VARBASE@/atheme
	fi
}

load_rc_config $name
run_rc_command "$1"
