#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: Geomyidae.sh,v 1.2 2008/08/12 14:59:44 reed Exp $
#

# PROVIDE: Geomyidae
# REQUIRE: DAEMON
# BEFORE:  LOGIN

$_rc_subr_loaded . /etc/rc.subr
#. /etc/rc.subr

name="Geomyidae"
rcvar="$name"
command="@PREFIX@/sbin/$name"

#####################################################
# Geomyidae Options Setion - "?" => Geomyidae(8)    #
#  Uncomment & define options (defaults are shown)  #
#####################################################
#
#LOGFILE="-l /var/log/gopherd.log"
#LOGLEVEL="-v 15"
#HTDOCS="-b /var/gopher"
#PORT="-p 70"
#SPORT="-o 70"
#USR="-u $USER"
#GRP="-g $GROUP"
#HOST="-h localhost"
#IP="-i 127.0.0.1"

######################################################
# Now remove any UNDEFINED options from line below:  #
######################################################
#
command_args="$LOGFILE $LOGLEVEL $HTDOCS $PORT $SPORT $USR $GRP $HOST $IP"


######################################################
#  Uncomment this section if a PID file is desired   #
######################################################
#
#pidfile="/var/run/${name}.pid"
#start_cmd="Geomyidae_start"
#
#Geomyidae_start()
#{
#        echo "Starting $name"
#        $name $command_args
#        pgrep -x $name > $pidfile
#}

######################################################
#  Lastly, add the following to /etc/rc.conf:        #
#  "Geomyidae=YES"  (without the quotes)             #
######################################################

load_rc_config $name
run_rc_command "$1"
