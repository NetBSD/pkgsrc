#!/sbin/sh

. /lib/svc/share/smf_include.sh

if [ ! -x @PREFIX@/sbin/hald ] ; then
	echo "@PREFIX@/sbin/hald not found or not executable"
	exit $SMF_EXIT_ERR_FATAL
fi

case "$1" in
'start')
	dir="@PKG_HOME.haldaemon@"
	if ! [ -d $dir ]; then
		@MKDIR@ -m 0755 $dir
		@CHOWN@ @HAL_USER@:@HAL_GROUP@ $dir
	fi

	if ! [ -d /media ]; then
		@MKDIR@ -m 755 /media
	fi

	@PREFIX@/sbin/hald --daemon=yes --use-syslog
	err=$?
	if [ $err -ne 0 ]; then
		echo "hal failed to start: error $err"
		exit $SMF_EXIT_ERR_FATAL
	fi
	;;
*)
        echo "Usage: $0 { start }"
	exit $SMF_EXIT_ERR_FATAL
        ;;
esac

exit $SMF_EXIT_OK
