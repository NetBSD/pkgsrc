#!@RCD_SCRIPTS_SHELL@

# PROVIDE: unifi
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
        . /etc/rc.subr
fi

name="unifi"
rcvar=$name
unifi_user="@UNIFI_USER@"
unifi_group="@UNIFI_GROUP@"
unifi_chdir="@PREFIX@/unifi"
command="@JAVA@"
# "--add-opens java.base/java.time=ALL-UNNAMED" to avoid
# 'module java.base does not "opens java.time" to unnamed module' error
java_args="--add-opens java.base/java.time=ALL-UNNAMED -Djava.awt.headless=true -Xmx1024M -Djava.net.preferIPv4Stack=true -Dorg.xerial.snappy.lib.path=@PREFIX@/unifi/lib -Dorg.xerial.lib.name=libsnappyjava.so -jar lib/ace.jar"
command_args="${java_args} start &"
stop_cmd="cd ${unifi_chdir} && ${command} ${java_args} stop"

load_rc_config $name
run_rc_command "$1"
