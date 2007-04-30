#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: teamspeak.sh,v 1.1.1.1 2007/04/30 15:33:27 abs Exp $
#
# PROVIDE: teamspeak
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set the following in /etc/rc.conf to start Teamspeak:
#
# teamspeak=YES

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="teamspeak"
rcvar=$name
teamspeak_user="@TSUSER@"
eval teamspeak_home="~$teamspeak_user"
extra_commands="passwords status"
start_cmd="teamspeak_doit start"
status_cmd="teamspeak_doit status"
stop_cmd="teamspeak_doit stop"
passwords_cmd="teamspeak_doit passwords"
pidfile="$teamspeak_home/tsserver2.pid"
logfile=$teamspeak_home/server.log

SHARE=@PREFIX@/share/teamspeak-server
SERVER=@PREFIX@/lib/teamspeak-server/teamspeak-server
SERVER_ARGS="-ini=$teamspeak_home/server.ini -sql=$SHARE/sqlite_sql/ -httpdocs=$SHARE/httpdocs/ -tcpquerydocs=$SHARE/tcpquerydocs/ -db=$teamspeak_home/server.dbs -log=$logfile -pid=$pidfile -badnames=$teamspeak_home/badnames.txt"

teamspeak_doit()
{
	case $1 in
	start)
	    if [ ! -d "$teamspeak_home" -o ! -w "$teamspeak_home" ] ; then
		echo "Unable to write to $teamspeak_home"
		exit 1
	    fi
	    if [ -e $pidfile ]; then
		    echo "$pidfile already exists...server already started ?";
		    echo "If you are sure the server is not running, delete $pidfile"
		    exit 1
	    else
		    echo "starting the teamspeak2 server"
		    doit_command="$SERVER $SERVER_ARGS"
		    doit="@SU@ -m $teamspeak_user -c '${doit_command}'"
		    eval $doit
	    fi
	    ;;
	stop)
	    if [ -e $pidfile ]; then
		    echo -n "stopping the teamspeak2 server"
		    if ( kill -TERM `cat $pidfile` ); then
			    for c in $(seq 1 300); do
				    if [ -e $pidfile ]; then
					    echo -n "."
					    sleep 1
				    fi
			    done
		    fi
		    if [ -e $pidfile ]; then
			    echo "server does not shutdown cleanly - killing"
			    kill -KILL `cat $pidfile`
			    rm $pidfile
			    sleep 5
		    else
			    echo "done"
		    fi
	    else
		    echo "$pidfile is missing, no started server ?"
		    exit 7
	    fi
	    ;;
	status)
	    if [ -e $pidfile ]; then
		    pid=`cat $pidfile`
		    if kill -0 "$pid" ; then
			echo "the server seems to be running: pid $pid"
			exit 0
		    else
			echo "the server seems to be stopped: pid $pid"
			exit 3
		    fi
	    else
		    echo "the server seems to be stopped"
		    exit 3
	    fi
	    ;;
	passwords)
	    if [ -e $logfile ]; then
		    date=$(cat $logfile | grep "admin account info: username: admin" | tail -n 1 | sed "s/^\([0-9]\+-[0-9]\+-[0-9]\+ [0-9]\+:[0-9]\+:[0-9]\+\).*$/\1/")
		    spass=$(cat $logfile | grep "superadmin account info: username: superadmin" | tail -n 1 | sed "s/^.*username: superadmin password: \([a-z0-9]\+\).*$/\1/")
		    pass=$(cat $logfile | grep "admin account info: username: admin" | tail -n 1 | sed "s/^.*username: admin password: \([a-z0-9]\+\).*$/\1/")
		    echo "Following passwords were generated on $date"
		    echo "superadmin = \"$spass\""
		    echo "admin	     = \"$pass\""
	    else
		    echo "$logfile not found, maybe you did not start the server yet ?"
		    exit 1
	    fi
	    ;;
	esac
}


if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	teamspeak_doit "$1"
fi


#	restart)
#		$0 stop && $0 start || exit 1
