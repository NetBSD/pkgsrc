#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: lima.sh,v 1.1 2026/05/26 00:31:52 khorben Exp $
#
# PROVIDE: lima
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start lima:
#
# lima=YES
#
# lima_instances	This required variable is a whitespace-separated list
#			of instances, e.g., lima_instances="default docker".

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="lima"
command="@PREFIX@/bin/limactl"
list_cmd="lima_list"
start_cmd="lima_start"
stop_cmd="lima_stop"
status_cmd="lima_status"
extra_commands="list"

lima_list()
{
	instances=
	for pidfile in ${lima_homedir}/.lima/*/ha.pid; do
		pid=$(check_pidfile "$pidfile" "$command")
		[ -n "$pid" ] || continue
		instance=${pidfile#$lima_homedir/.lima/}
		instance=${instance%/ha.pid}
		instances="$instances $instance"
	done
	[ -z "$instances" ] || echo $instances
}

lima_start()
{
	echo "Starting ${name}."

	failed=
	for instance in $lima_instances; do
		case "$instance" in
		"")	continue ;;
		esac

		# Run limactl to start the instance.
		name="$name instance: $instance" flags="start" \
			command_args="$instance $lima_flags" \
			start_cmd= run_rc_command "faststart"
		[ $? -eq 0 ] || failed="$failed $instance"
	done
	if [ -n "$failed" ]; then
		echo "$name: could not start instance:$failed." 1>&2
	fi
}

lima_status() {
	command_args="list"
	start_cmd= run_rc_command "faststart"
}

lima_stop()
{
	echo "Stopping ${name}."

	failed=
	stopped=
	for instance in $(lima_list); do
		case "$instance" in
		"")	continue ;;
		esac

		command_args="$instance"
		name="$name instance: $instance" flags="stop" \
			start_cmd= run_rc_command "faststart" \
			| sed "s/^Starting $name/Stopping $name/"
		if [ $? -eq 0 ]; then
			stopped="$stopped $instance"
		else
			failed="$failed $instance"
		fi
	done
	if [ -n "$failed" ]; then
		echo "$name: could not stop instance:$failed." 1>&2
	fi
}

: ${lima_homedir="@LIMA_USER_HOME@"}
: ${lima_instances="default"}

lima_flags="-y"
lima_user="@LIMA_USER@"
lima_group="@LIMA_GROUP@"

cd /

load_rc_config $name

lima_env="HOME=${lima_homedir}"
lima_env="${lima_env} USER=$lima_user"
lima_env="${lima_env} PATH=$PATH:@PREFIX@/bin"

run_rc_command "$1"
