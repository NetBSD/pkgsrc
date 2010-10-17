#! @RCD_SCRIPTS_SHELL@
#
# $NetBSD: cassandra.sh,v 1.2 2010/10/17 23:41:12 tonnerre Exp $
#
# PROVIDE: cassandra
# REQUIRE: DAEMON
#

if [ -r /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="cassandra"
rcvar=$name
command="@CASSANDRA_HOME@/bin/cassandra"
pidfile="@VARBASE@/run/cassandra/cassandra.pid"
cassandra_user="@CASSANDRA_USER@"
cassandra_group="@CASSANDRA_GROUP@"
start_cmd="$command start"
stop_cmd="$command stop"
restart_cmd="$stop_cmd && $start_cmd"
run_cmd="cassandra_run"
version_cmd="cassandra_version"
debug_cmd="cassandra_debug"
extra_commands="run version debug"
start_precmd="cassandra_precmd"

PREFIX=@PREFIX@

if [ -z "${JAVA_HOME}" ]
then
	JAVA_HOME="@JAVA_HOME@"
	export JAVA_HOME
fi

CATALINA_HOME=@CASSANDRA_HOME@
CASSANDRA_HOME=@CASSANDRA_HOME@
CASSANDRA_CONF=@PKG_SYSCONFBASE@/cassandra
CATALINA_PID=${pidfile}
export CATALINA_HOME
export CASSANDRA_HOME
export CASSANDRA_CONF
export CATALINA_PID

find ${PREFIX}/lib -type f -name \*.jar -print | while read jar
do
	CLASSPATH=${CLASSPATH}:${jar}
done
unset jar

if [ -n "${cassandra_classpath}" ]
then
	CLASSPATH=${CLASSPATH}:${cassandra_classpath}
fi
export CLASSPATH

cassandra_precmd()
{
	if [ ! -d @VARBASE@/run/cassandra ]; then
		@MKDIR@ @VARBASE@/run/cassandra
		@CHMOD@ 0750 @VARBASE@/run/cassandra
		@CHOWN@ ${cassandra_user}:${cassandra_group} @VARBASE@/run/cassandra
	fi
}

cassandra_start()
{
	cd $CATALINA_HOME/logs
	@SU@ ${cassandra_user} -c "${command} start"
}

cassandra_stop()
{
	rc_pid=$(check_pidfile $pidfile "${JAVA_HOME}/bin/java")
	@SU@ ${cassandra_user} -c "${command} stop"
	wait_for_pids $rc_pid
}


cassandra_run()
{
	cd ${CATALINA_HOME}/logs
	@SU@ ${cassandra_user} -c "${command} run"
}

cassandra_version()
{
	@SU@ ${cassandra_user} -c "${command} version"
}

cassandra_debug()
{
	cd ${CATALINA_HOME}/logs
	@SU@ ${cassandra_user} -c "${command} debug"
}

if [ -f /etc/rc.subr ]
then
	load_rc_config "$name"
	run_rc_command "$1"
else
	echo -n ' ${name}'
	exec ${command} ${cassandra_flags} ${command_args}
fi
