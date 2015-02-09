#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: fail2ban
# REQUIRE: NETWORKING syslogd
#
# Add the following lines to /etc/rc.conf to enable fail2ban:
# fail2ban=YES
# fail2ban_flags="<set as needed>"

. /etc/rc.subr

name="@PKGBASE@"
rcvar=${name}
command="@PREFIX@/bin/fail2ban-server"
command_interpreter="@PYTHON_INTERP@"
client="@PREFIX@/bin/fail2ban-client"
pidfile="@VARBASE@/${name}/${name}.pid"
extra_commands="reload"

load_rc_config ${name}

start_precmd="fail2ban_precmd"
start_cmd="${client} ${fail2ban_flags} start"
stop_cmd="${client} ${fail2ban_flags} stop"
status_cmd="${client} ${fail2ban_flags} status"
reload_cmd="${client} ${fail2ban_flags} reload"

fail2ban_precmd () {
    mkdir -p /var/run/fail2ban
}

run_rc_command "$1"
