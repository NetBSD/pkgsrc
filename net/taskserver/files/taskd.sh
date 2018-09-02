#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: taskd.sh,v 1.1 2018/09/02 09:53:14 triaxx Exp $
#

# PROVIDE: taskd
# REQUIRE: NETWORKING FILESYSTEMS
# BEFORE:  DAEMON

. /etc/rc.subr

name="taskd"
rcvar="${name}"
procname="@PREFIX@/bin/${name}"
command="@PREFIX@/bin/${name}ctl"
command_args="$1"
extra_commands="reload"
taskd_env="TASKDDATA=@TASKD_DATA@"
taskd_user="@TASKD_USER@"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then 
  load_rc_config "${name}"
elif [ -f @PKG_SYSCONFDIR@/rc.conf ]; then
  . @PKG_SYSCONFDIR@/rc.conf
fi

run_rc_command "$1"
