#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rspamd.sh,v 1.1 2017/03/20 14:15:16 wiz Exp $
#
# PROVIDE: rspamd
# REQUIRE: DAEMON
# BEFORE: mail

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="rspamd"
rcvar=$name
command="@PREFIX@/bin/rspamd"
pidfile="@VARBASE@/run/rspamd/${name}.pid"
command_args="-c @PKG_SYSCONFDIR@/rspamd.conf"
required_files="@PKG_SYSCONFDIR@/rspamd.conf"
start_precmd="rspamd_precmd"

rspamd_precmd()
{
	if [ ! -d @VARBASE@/run/rspamd ]; then
		@MKDIR@ @VARBASE@/run/rspamd
		@CHMOD@ 0755 @VARBASE@/run/rspamd
		@CHOWN@ @RSPAMD_USER@:@RSPAMD_GROUP@ @VARBASE@/run/rspamd
	fi
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${rspamd_flags} ${command_args}
fi

