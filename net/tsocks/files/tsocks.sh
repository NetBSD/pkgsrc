#! @SH@

libtsocks="@PREFIX@/lib/libtsocks.so"

usage() {
	echo "usage:"
	echo "  $0 [program [arguments...]]"
	echo "  . $0 on"
	echo "  . $0 off"
}

tsocks_on() {
	case $LD_PRELOAD in
	*"$libtsocks"*)
		;;
	"")	LD_PRELOAD="$libtsocks"
		;;
	*)	LD_PRELOAD="$LD_PRELOAD $libtsocks"
		;;
	esac
	export LD_PRELOAD
}

tsocks_off() {
	LD_PRELOAD=`echo $LD_PRELOAD | sed 's,$libtsocks[ :]?,,'`
	if [ "$LD_PRELOAD" ]; then
		export LD_PRELOAD
	else
		unset LD_PRELOAD
	fi
}

if [ $# -eq 0 ]; then
	set -- ${SHELL:-/bin/sh}
fi

case "$1" in
on)
	tsocks_on
	;;
off)
	tsocks_off
	;;

show | sh)
	echo "LD_PRELOAD=\"$LD_PRELOAD\""
	;;
-h | -?)
	usage
	;;
-*)	usage 1>&2
	exit 1
	;;
*)
	tsocks_on
	exec "$@"
	;;
esac
