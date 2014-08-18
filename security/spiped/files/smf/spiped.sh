#!@SMF_METHOD_SHELL@
#
# $NetBSD: spiped.sh,v 1.2 2014/08/18 22:19:16 wiedi Exp $
#
# Init script for spiped.
#

. /lib/svc/share/smf_include.sh

getproparg() {
	svcprop -p $1 $SMF_FMRI
}

MODE=$(  getproparg spiped/mode)
SOURCE=$(getproparg spiped/source)
TARGET=$(getproparg spiped/target)
KEY=$(   getproparg spiped/key)

case "$MODE" in
	encrypt)
		MODEFLAG="-e"
		;;
	decrypt)
		MODEFLAG="-d"
		;;
	*)
		echo Invalid value for spiped/mode: $MODE
		exit $SMF_EXIT_ERR_CONFIG
esac

@LOCALBASE@/bin/spiped -F $MODEFLAG -s "$SOURCE" -t "$TARGET" -k "$KEY"

exit $SMF_EXIT_OK
