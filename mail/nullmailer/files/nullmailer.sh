#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nullmailer.sh,v 1.5 2017/10/28 04:51:06 schmonz Exp $
#
# @PKGNAME@ script to control nullmailer (simple relay-only MTA).
#

# PROVIDE: mail

name="nullmailer"

# User-settable rc.conf variables and their default values:
: ${nullmailer_postenv:=""}
: ${nullmailer_logcmd:="logger -t nb${name} -p mail.info"}

if [ -f /etc/rc.subr ]; then
    . /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/nullmailer/remotes"
required_dirs="@VARBASE@/spool/nullmailer/queue @VARBASE@/spool/nullmailer/tmp"
command="@PREFIX@/libexec/nullmailer/nullmailer-send"
start_precmd="nullmailer_prestart"

nullmailer_prestart()
{
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${nullmailer_postenv}
@PREFIX@/bin/setuidgid @NULLMAILER_USER@ @PREFIX@/libexec/nullmailer/nullmailer-send
2>&1 |
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @NULLMAILER_USER@ ${nullmailer_logcmd}"
	command_args="&"
	rc_flags=""
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	nullmailer_prestart
	eval ${command} ${nullmailer_flags} ${command_args}
	nullmailer_poststart
fi
