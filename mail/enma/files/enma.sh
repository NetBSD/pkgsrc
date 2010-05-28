#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: enma.sh,v 1.3 2010/05/28 07:26:48 obache Exp $
#
# PROVIDE: enma
# REQUIRE: NETWORK
#

. /etc/rc.subr

name="enma"
rcvar=${name}
command="@PREFIX@/libexec/enma"
pidfile="@VARBASE@/run/enma/${name}.pid"
required_files="@PKG_SYSCONFDIR@/enma.conf"
command_args="-c @PKG_SYSCONFDIR@/enma.conf"

start_precmd="${name}_prestart"

enma_prestart()
{
	if [ ! -d @VARBASE@/run/enma ]; then
		@MKDIR@ @VARBASE@/run/enma
		@CHOWN@ @ENMA_USER@ @VARBASE@/run/enma
		@CHGRP@ @ENMA_GROUP@ @VARBASE@/run/enma
		@CHMOD@ 0700 @VARBASE@/run/enma
	fi
}

load_rc_config ${name}
run_rc_command "$1"
