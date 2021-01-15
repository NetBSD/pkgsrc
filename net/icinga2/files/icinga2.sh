#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: icinga2.sh,v 1.1 2021/01/15 00:37:17 wiz Exp $
#
# PROVIDE: icinga2
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="icinga2"
rcvar=${name}
command="/usr/pkg/sbin/icinga2"
procname="/usr/pkg/lib/icinga2/sbin/icinga2"
pidfile="/var/run/icinga2/icinga2.pid"
icinga2_chdir="/" # Icinga2 doesn't deamonize properly
icinga2_env="ICINGA2_USER=@ICINGA2_USER@ ICINGA2_GROUP=@ICINGA2_GROUP@" # ICINGA2_RLIMIT_FILES ICINGA2_RLIMIT_PROCESSES ICINGA2_RLIMIT_STACK
start_precmd="icinga2_start_precmd"
reload_precmd="icinga2_reload_precmd"
extra_commands="reload checkconfig"
checkconfig_cmd="icinga2_checkconfig"

# Check configuration (noisy)
icinga2_checkconfig() {
	${command} daemon -C -x information ${icinga2_flags}
}

# Less noisy (-x critical) than icinga2_checkconfig
icinga2_reload_precmd() {
	${command} daemon -C -x critical ${icinga2_flags}
}

icinga2_start_precmd() {
	# Set owner/permission on /var/run files (may be a tempfs)
	if ! [ -d "@RUNDIR@" ]; then
		@MKDIR@ -p "@RUNDIR@" "@RUNDIR@/cmd"
		@CHOWN@ @ICINGA2_USER@:@ICINGA2_COMMAND_GROUP@ "@RUNDIR@" "@RUNDIR@/cmd"
		@CHMOD@ 0751 "@RUNDIR@" # icinga2.spec says 0750, but that makes the PID file inaccessable
		@CHMOD@ 2750 "@RUNDIR@/cmd"
	fi
	# Create plugin state directory (depends on $NAGIOS_PLUGIN_STATE_DIRECTORY)
	: ${NAGIOS_PLUGIN_STATE_DIRECTORY:="@NAGIOS_PLUGIN_STATE_DIRECTORY@"}
	if ! [ -d "$NAGIOS_PLUGIN_STATE_DIRECTORY" ]; then
		@MKDIR@ "$NAGIOS_PLUGIN_STATE_DIRECTORY"
		@CHOWN@ @ICINGA2_USER@:@ICINGA2_GROUP@ "$NAGIOS_PLUGIN_STATE_DIRECTORY"
		@CHMOD@ 775 "$NAGIOS_PLUGIN_STATE_DIRECTORY"
	fi
}

load_rc_config $name

# The deamon is invoked by "icinga2 daemon" and needs an additional -d
#  to actually deamonize.
# Also use -x critical to comply with "no news is good news" mantra.
# See icinga2_chdir above for an additional step requred to properly daemonize.
flags="daemon -d -x critical ${icinga2_flags}"

run_rc_command "$1"
