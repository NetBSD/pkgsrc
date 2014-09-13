#!/sbin/sh

. /lib/svc/share/smf_include.sh

# SMF_FMRI is the name of the target service. This allows multiple instances
# to use the same script.

if [ ! -x @PREFIX@/bin/dbus-daemon ]; then
	echo "@PREFIX@/bin/dbus-daemon not found or not executable"
	exit $SMF_EXIT_ERR_FATAL
fi

if [ ! -f @VARBASE@/db/dbus/machine-id ]; then
	@PREFIX@/bin/dbus-uuidgen --ensure
fi

case "$1" in
'start')
	if [ -f @VARBASE@/run/dbus/pid ]; then
		rm -f @VARBASE@/run/dbus/pid
	fi
	@PREFIX@/bin/dbus-daemon --system
	err=$?
	if [ $err -ne 0 ]; then
		echo "dbus failed to start: error $err"
		exit $SMF_EXIT_ERR_FATAL
	fi
	;;
*)
	echo "Usage: $0 { start }"
	exit $SMF_EXIT_ERR_FATAL 
    ;;
esac

exit $SMF_EXIT_OK
