#!@SMF_METHOD_SHELL@
#
# $NetBSD: openvpn.sh,v 1.1 2014/09/08 16:57:01 wiedi Exp $
#
# Init script for openvpn (SMF).
#
. /lib/svc/share/smf_include.sh




METHOD=$1
CONFIG=$2
PATH="@PREFIX@/sbin:@PREFIX@/bin:@PREFIX@/gnu/bin:/usr/bin:/usr/sbin"
SCRIPTNAME=$(basename $0)
INSTANCE=$(echo $SMF_FMRI | sed s_.*:__)
PIDFILE="@VARBASE@/run/openvpn-$INSTANCE.pid"

case $METHOD in
start)
	if [[ ! -f $CONFIG ]]
	then
		echo "ERROR: Openvpn config file \""$CONFIG"\" doesn't exist"
		exit $SMF_EXIT_ERR_CONFIG
	fi
	@PREFIX@/sbin/openvpn --config ${CONFIG} --writepid ${PIDFILE}

;;
stop)
	if [[ -s ${PIDFILE} ]]
	then
		kill $(cat ${PIDFILE}) 2>/dev/null
		[[ $? -eq 0 ]] && rm -f ${PIDFILE}

	else
		echo "ERROR: \""$PIDFILE"\" pidfile  doesn't exist"
		exit $SMF_EXIT_ERR_CONFIG
	fi
;;

*)
	echo "usage : "
	echo "$SCRIPTNAME { start | stop } "
	echo ""
	exit $SMF_EXIT_ERR_CONFIG
esac

exit $SMF_EXIT_OK
