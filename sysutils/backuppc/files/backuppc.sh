#!@RCD_SCRIPTS_SHELL@

# PROVIDE: backuppc
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
        . /etc/rc.subr
fi

name="backuppc"
rcvar=$name
start_precmd="backuppc_precmd"
reload_cmd="backuppc_reload"
backuppc_user="@BACKUPPC_USER@"
backuppc_group="@BACKUPPC_GROUP@"
extra_commands="reload"
command="@PREFIX@/share/BackupPC/bin/BackupPC"
command_args="-d"
command_interpreter="@PREFIX@/bin/perl"

load_rc_config $name

backuppc_precmd() {
    mkdir -p "@VARBASE@/run/BackupPC"
    chown "${backuppc_user}:${backuppc_group}" "@VARBASE@/run/BackupPC"
    chmod 750 "@VARBASE@/run/BackupPC"
}

backuppc_reload()
{
    pkill -1 -f "@PREFIX@/share/BackupPC/bin/BackupPC -d"
    echo "${name} reloaded"
}

run_rc_command "$1"
