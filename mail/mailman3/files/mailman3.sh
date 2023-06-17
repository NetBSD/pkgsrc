#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mailman3.sh,v 1.2 2023/06/17 01:28:02 markd Exp $
#
# PROVIDE: mailman3
# REQUIRE: mail
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="mailman3"
rcvar=$name
command="@PREFIX@/bin/mailman"
#command_args="-C ${mailman_config}"
start_cmd="mailman_doit start --force"
stop_cmd="mailman_doit stop"
restart_cmd="mailman_doit restart"
status_cmd="mailman_doit status"
info_cmd="mailman_doit info"
extra_commands=info
start_precmd=mailman_prestart

mailman_prestart() {
	dir="@VARBASE@/run/mailman"
	if @TEST@ ! -d $dir; then
		@MKDIR@ -p $dir
		@CHMOD@ 0755 $dir
		@CHOWN@ @MAILMAN_USER@:@MAILMAN_GROUP@ $dir
	fi
}

mailman_doit()
{
	LANG=en_US.UTF-8 @SU@ -m @MAILMAN_USER@ -c "${command} ${command_args} $*"
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	mailman_doit "$1"
fi
