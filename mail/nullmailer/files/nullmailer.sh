#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nullmailer.sh,v 1.4 2009/10/14 21:13:41 plunky Exp $
#
# PROVIDE: mail
# REQUIRE: LOGIN

if [ -f /etc/rc.subr ]; then
    . /etc/rc.subr
fi

name="nullmailer"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/nullmailer/remotes"
required_dirs="@VARBASE@/spool/nullmailer/queue @VARBASE@/spool/nullmailer/tmp"
command="@PREFIX@/libexec/nullmailer/nullmailer-daemon"
procname="@PREFIX@/libexec/nullmailer/nullmailer-send"

nullmailer_user="@NULLMAILER_USER@"
nullmailer_group="@NULLMAILER_GROUP@"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	${command} ${nullmailer_flags} ${command_args}
fi
