#! @RCD_SCRIPTS_SHELL@
#
# $NetBSD: elasticsearch.sh,v 1.5 2018/04/06 15:48:46 fhajny Exp $
#
# PROVIDE: elasticsearch
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="elasticsearch"
rcvar=$name
pidfile="@ES_PIDDIR@/elasticsearch.pid"
required_files="@PKG_SYSCONFDIR@/elasticsearch.yml"
start_precmd="elasticsearch_precmd"

: ${elasticsearch_user:=@ES_USER@}
: ${elasticsearch_group:=@ES_GROUP@}
: ${elasticsearch_config:="@PKG_SYSCONFDIR@/elasticsearch.yml"}
: ${elasticsearch_min_mem:="1g"}
: ${elasticsearch_max_mem:="1g"}
: ${elasticsearch_props:=""}
: ${elasticsearch_fdlimit:="768"}

ES_CLASSPATH="@ES_BASEDIR@/lib/@DISTNAME@.jar:@ES_BASEDIR@/lib/*"

command="@PKG_JAVA_HOME@/bin/java"
# flags taken from bin/elasticsearch and bin/elasticsearch.in.sh
command_args="	-Delasticsearch					\
		-Des.path.home=@ES_BASEDIR@			\
		-Des.path.conf=@PKG_SYSCONFDIR@			\
		-Des.pidfile=${pidfile}				\
		-Dfile.encoding=UTF-8				\
		-Djava.awt.headless=true			\
		-Xms${elasticsearch_min_mem}			\
		-Xmx${elasticsearch_max_mem}			\
		-Xss256k					\
		-XX:+DisableExplicitGC				\
		-XX:+HeapDumpOnOutOfMemoryError			\
		-XX:+UseCMSInitiatingOccupancyOnly		\
		-XX:+UseCMSInitiatingOccupancyOnly		\
		-XX:+UseConcMarkSweepGC				\
		-XX:+UseParNewGC				\
		-XX:CMSInitiatingOccupancyFraction=75		\
		-cp ${ES_CLASSPATH}				\
		${elasticsearch_props}				\
		org.elasticsearch.bootstrap.Elasticsearch	\
		>/dev/null &"

# ElasticSearch is fd hungry, default limit leads to write locks
SOFT_FDLIMIT=`ulimit -S -n`
HARD_FDLIMIT=`ulimit -H -n`

if [ ${elasticsearch_fdlimit} -gt ${SOFT_FDLIMIT} ]; then
	if [ ${elasticsearch_fdlimit} -le ${HARD_FDLIMIT} ]; then
		ulimit -S -n ${elasticsearch_fdlimit}
	else
		ulimit -S -n ${HARD_FDLIMIT}
	fi
fi

elasticsearch_precmd()
{
	@TOUCH@ ${pidfile}
	@CHOWN@ ${elasticsearch_user}:${elasticsearch_group} ${pidfile}
}

load_rc_config "$name"
run_rc_command "$1"
