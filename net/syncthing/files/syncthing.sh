#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: syncthing.sh,v 1.2 2019/07/17 01:37:11 nia Exp $
#
# PROVIDE: syncthing
# REQUIRE: DAEMON

. /etc/rc.subr

name="syncthing"
rcvar=${name}

load_rc_config $name

: ${syncthing_user:=@SYNCTHING_USER@}
: ${syncthing_user_home:=@VARBASE@/db/syncthing}
: ${syncthing_group:=@SYNCTHING_GROUP@}
: ${syncthing_home:=@PKG_SYSCONFDIR@}
: ${syncthing_logfile:=@VARBASE@/log/syncthing.log}

command="@PREFIX@/bin/syncthing"
command_args="-logfile ${syncthing_logfile}"
command_args="${command_args} -home ${syncthing_home} > /dev/null &"

syncthing_env="STNODEFAULTFOLDER=1"
syncthing_env="${syncthing_env} USER=${syncthing_user}"
syncthing_env="${syncthing_env} HOME=${syncthing_user_home}"

start_precmd="syncthing_precmd"

syncthing_precmd()
{
	@TOUCH@ ${syncthing_logfile} && \
	@CHOWN@ ${syncthing_user}:${syncthing_group} ${syncthing_logfile} && \
	@CHMOD@ 0750 ${syncthing_logfile}
}

run_rc_command "$1"
