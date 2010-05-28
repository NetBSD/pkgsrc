#! @RCD_SCRIPTS_SHELL@
#
# $NetBSD: milter-manager.sh,v 1.3 2010/05/28 07:40:22 obache Exp $
#

# PROVIDE: milter-manager
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: shutdown

. /etc/rc.subr

name="milter_manager"
rcvar=$name
command="@PREFIX@/sbin/milter-manager"
pidfile="@VARBASE@/run/milter-manager/milter-manager.pid"
command_args="--daemon"
extra_command="reload"

start_precmd="${name}_prestart"

milter_manager_prestart()
{
	if [ ! -d @VARBASE@/run/milter-manager ]; then
		@MKDIR@ @VARBASE@/run/milter-manager
		@CHOWN@ @MILTER_MANAGER_USER@ @VARBASE@/run/milter-manager
		@CHGRP@ @MILTER_MANAGER_GROUP@ @VARBASE@/run/milter-manager
		@CHMOD@ 0755 @VARBASE@/run/milter-manager
	fi
}

load_rc_config ${name}
run_rc_command "$1"
