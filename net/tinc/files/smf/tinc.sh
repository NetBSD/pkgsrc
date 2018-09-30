#!@SMF_METHOD_SHELL@
#
# Init script for tinc (SMF)
#

. /lib/svc/share/smf_include.sh

getproparg() {
	svcprop -p $1 $SMF_FMRI 2>/dev/null
}

METHOD=$1
INSTANCE=$(echo $SMF_FMRI | sed s_.*:__)
INSTANCE=${INSTANCE:=default}

LOGDIR="@VARBASE@/log/tinc"
LOGFILE="${LOGDIR}/tinc.${INSTANCE}.log"
PIDFILE="@VARBASE@/run/tinc.${INSTANCE}.pid"
_USER=$(getproparg tinc/user)
_CHROOT=$(getproparg tinc/chroot)
_MEMLOCK=$(getproparg tinc/memlock)

USER=${_USER:=tinc}

TINC_FLAGS=""

# Check if there is a configuration directory for this instance
if [ ! -d @PKG_SYSCONFDIR@/${INSTANCE} ]; then
	echo "$0: No configuration directory found"
	exit $SMF_EXIT_ERR_CONFIG
fi

# Chroot tinc into its config directory
if [ "${_CHROOT}" == "true" ]; then
	TINC_FLAGS="${TINC_FLAGS} -R"
fi

# Lock tinc memory to avoid going into swap
if [ "${_MEMLOCK}" == "true" ]; then
	TINC_FLAGS="${TINC_FLAGS} -L"
fi

case ${METHOD} in
start)
	@PREFIX@/sbin/tincd -n ${INSTANCE} -U ${USER} ${TINC_FLAGS} --logfile=${LOGFILE} --pidfile=${PIDFILE}
	;;
stop)
	@PREFIX@/sbin/tincd -n ${INSTANCE} -k --pidfile=${PIDFILE}
	;;
esac

exit ${SMF_EXIT_OK}
