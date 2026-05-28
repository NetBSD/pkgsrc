#!/bin/sh
#
# $NetBSD: dmarcrepv.sh,v 1.1 2026/05/28 16:13:39 ryoon Exp $
#
# PROVIDE: dmarcrepv
# REQUIRE: DAEMON

. /etc/rc.subr

name="dmarcrepv"
rcvar=$name
pidfile="@VARBASE@/run/${name}.pid"
start_cmd="dmarcrepv_start"
stop_cmd="dmarcrepv_stop"
status_cmd="dmarcrepv_status"
extra_commands="status"

#export IMAP_HOST=imap.example.com
#export IMAP_USER=imapuser
#export IMAP_PASSWORD=imappassword
#export IMAP_PORT=993
#export HTTP_SERVER_USER=webuiuser
#export HTTP_SERVER_PASSWORD=webuipassword
#export HTTP_SERVER_PORT=8080

#export IMAP_STARTTLS=false

export DEBUG_LEVEL=INFO

dmarcrepv_start()
{
	if test -f "${pidfile}"; then
		@ECHO@ "Already running ${name}."
	else
		@SU@ @DMARCREPV_USER@ -c \
			"@PREFIX@/bin/dmarc-report-viewer \
			--imap-host $IMAP_HOST \
			--imap-user $IMAP_USER \
			--imap-password $IMAP_PASSWORD \
			--imap-port $IMAP_PORT \
			--http-server-port $HTTP_SERVER_PORT \
			--http-server-user $HTTP_SERVER_USER \
			--http-server-password $HTTP_SERVER_PASSWORD \
			--log-level $DEBUG_LEVEL \
			>> @DMARCREPV_HOME@/dmarc-report-viewer.log 2>&1" &
		echo $! > ${pidfile}
	fi
}

dmarcrepv_stop()
{
	kill ${sig_stop} `cat ${pidfile}`
	rm ${pidfile}
}

dmarcrepv_status()
{
	if test -f ${pidfile}; then
		echo "${name} is running as pid `cat ${pidfile}`."
	else
		echo "${name} is not running."
	fi

}

load_rc_config $name
run_rc_command "$1"
