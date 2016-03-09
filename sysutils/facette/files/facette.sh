#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: facette.sh,v 1.1 2016/03/09 12:09:29 imil Exp $
#
# PROVIDE: facette 
# REQUIRE: DAEMON network
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="facette"
rcvar=$name
command="@PREFIX@/bin/facette"
command_args="-l @FACETTE_LOGDIR@/${name}.log &"
facette_user="@FACETTE_USER@"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	@SU@ -m ${facette_user} -c "${command} ${command_args}"
fi
