#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: hylafax.sh,v 1.4 2002/09/20 02:01:55 grant Exp $
#
# PROVIDE: hylafax
# REQUIRE: DAEMON

command=${1:-start}

case ${command} in
start)
	if [ -x @PREFIX@/libexec/hfaxd -a -f /var/spool/hylafax/etc/config ] ; then
	    echo -n 'Starting hfaxd'
	    @PREFIX@/libexec/hfaxd -i 4559 -o 4557 -s 444 

	    echo ' faxq.'
	    @PREFIX@/sbin/faxq
	fi
	;;
stop)
	PIDS=`ps -ax -o pid,command|egrep '[ /](faxq|hfaxd) '|awk '{printf " " $1}'`
	if [ -n "$PIDS" ];then
		echo "Stopping hylafax pids$PIDS."
		kill -TERM $PIDS
	else
		echo "hylafax not running?"
	fi
	;;
restart)
	( $0 stop )
	sleep 1
	$0 start
	;;
esac
exit 0
