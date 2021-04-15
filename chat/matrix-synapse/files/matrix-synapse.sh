#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: matrix-synapse
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
  . /etc/rc.subr
fi

name="matrix-synapse"
rcvar="matrix_synapse"
ctl_command="@PREFIX@/bin/synctl"
conf_file="@PKG_SYSCONFDIR@/homeserver.yaml"
required_files="$conf_file"
pidfile="@SYNAPSE_DATA@/homeserver.pid"
#start_precmd="ulimit -n 2048"
: ${synapse_user:=@SYNAPSE_USER@}

start_cmd="@SU@ -m ${synapse_user} -c '${ctl_command} start $conf_file'"
stop_cmd="@SU@ -m ${synapse_user} -c '${ctl_command} stop $conf_file'"

load_rc_config $name
run_rc_command "$1"
