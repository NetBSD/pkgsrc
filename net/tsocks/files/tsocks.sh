#!@SH@

libtsocks="@PREFIX@/lib/libtsocks.@SOEXT@"

usage() {
	echo "usage:"
	echo "  $0 [program [arguments...]]"
	echo "  . $0 on"
	echo "  . $0 off"
}

tsocks_on() {
	case $@PRELOAD_VAR@ in
	*"$libtsocks"*)
		;;
	"")	@PRELOAD_VAR@="$libtsocks"
		;;
	*)	@PRELOAD_VAR@="$@PRELOAD_VAR@ $libtsocks"
		;;
	esac
	export @PRELOAD_VAR@
	if [ "@PRELOAD_VAR@" = "DYLD_INSERT_LIBRARIES" ]; then
		export DYLD_FORCE_FLAT_NAMESPACE=1
	fi
}

tsocks_off() {
	@PRELOAD_VAR@=`echo $@PRELOAD_VAR@ | sed 's,$libtsocks[ :]?,,'`
	if [ "$@PRELOAD_VAR@" ]; then
		export @PRELOAD_VAR@
	else
		unset @PRELOAD_VAR@
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
	echo "@PRELOAD_VAR@=\"$@PRELOAD_VAR@\""
	if [ "@PRELOAD_VAR@" = "DYLD_INSERT_LIBRARIES" ]; then
		echo "DYLD_FORCE_FLAT_NAMESPACE=${DYLD_FORCE_FLAT_NAMESPACE}"
	fi
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
