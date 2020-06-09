#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: solr.sh,v 1.1 2020/06/09 22:20:01 jym Exp $
#
# Apache Solr daemon
# 
# PROVIDE: solr
# REQUIRE: LOGIN
# 
# You will need to set some variables in /etc/rc.conf to start Solr:
# 
# solr=YES
# solr_port=@SOLR_PORT@	# Solr binding port number;
# 			#   this variable is optional and defaults to "@SOLR_PORT@".
#

. /etc/rc.subr

name="solr"
rcvar=$name
command="@PREFIX@/bin/solr"
pidfile="@SOLR_PIDDIR@/solr-${solr_port}.pid"
solr_user="@SOLR_USER@"
solr_group="@SOLR_GROUP@"
solr_home="@SOLR_HOME@"
required_files="@PKG_SYSCONFDIR@/solr.in.sh @PKG_SYSCONFDIR@/solr.xml"

start_precmd="solr_precmd"
start_cmd="solr_start"
status_cmd="solr_status"
stop_cmd="solr_stop"

solr_precmd()
{
	# Solr defaults are often too low for most OSes (especially NetBSD)
	ulimit -m unlimited
	ulimit -n 65000
	ulimit -p 65000

	# Solr insists on having its xml file accessible from its
	# HOME db directory 
	if [ \! -e ${solr_home}/solr.xml ]; then
		ln -sf @PKG_SYSCONFDIR@/solr.xml ${solr_home}/solr.xml
	fi
}

solr_start()
{
	@SU@ -m ${solr_user} -c "${command} start ${command_args}"
}

solr_status()
{
	@SU@ -m ${solr_user} -c "${command} status ${command_args}"
}

solr_stop()
{
	rc_pid=$(check_pidfile $pidfile "${JAVA_HOME}/bin/java")
	@SU@ -m ${solr_user} -c "${command} stop ${command_args}"
	wait_for_pids $rc_pid
}

load_rc_config "$name"

if [ -z "${solr_port}" ]; then
	solr_port="@SOLR_PORT@"
fi

if [ -z "${JAVA_HOME}" ]; then
	JAVA_HOME="@JAVA_HOME@"
	export JAVA_HOME
fi

command_args="-p ${solr_port}"

run_rc_command "$1"
