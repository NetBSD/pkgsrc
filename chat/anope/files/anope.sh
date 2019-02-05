#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: anope.sh,v 1.2 2019/02/05 19:10:50 nia Exp $
#
# PROVIDE: anope
# REQUIRE: DAEMON

. /etc/rc.subr

name="anope"
rcvar=${name}
command="@PREFIX@/bin/anope"
command_args="--confdir=@PKG_SYSCONFDIR@/anope"
command_args="${command_args} --dbdir=@PREFIX@/anope/data"
command_args="${command_args} --localedir=@PREFIX@/@PKGLOCALEDIR@/locale"
command_args="${command_args} --logdir=@PREFIX@/anope/logs"
command_args="${command_args} --modulesdir=@PREFIX@/lib/anope"
required_files="@PKG_SYSCONFDIR@/anope/services.conf"
pidfile="@PREFIX@/anope/${name}.pid"

anope_user="@ANOPE_USER@"
anope_group="@ANOPE_GROUP@"

extra_commands="support"
support_cmd="anope_support"

anope_support()
{
	if [ ! -f ${required_files} ]; then
		warn "${required_files} does not exist."
		return 1;
	fi
	su -m ${anope_user}:${anope_group} -c "${command} ${command_args} --support"
}

load_rc_config $name
run_rc_command "$1"
