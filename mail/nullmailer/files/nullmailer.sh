#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nullmailer.sh,v 1.2 2005/08/20 02:20:45 schmonz Exp $
#
# PROVIDE: mail
# REQUIRE: LOGIN

if [ -f /etc/rc.subr ]; then
    . /etc/rc.subr
fi

name="nullmailer"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/nullmailer/remotes"
required_files="${required_files} @VARBASE@/spool/nullmailer/trigger"
required_dirs="@VARBASE@/spool/nullmailer/queue @VARBASE@/spool/nullmailer/tmp"
command="@PREFIX@/libexec/nullmailer/nullmailer-send"
command_args="2>&1 | logger -t nullmailer -p mail.info &"

nullmailer_user="@NULLMAILER_USER@"
nullmailer_group="@NULLMAILER_GROUP@"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	${command} ${nullmailer_flags} ${command_args}
fi
