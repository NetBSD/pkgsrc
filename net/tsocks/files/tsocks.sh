#!@SH@

if [ $# -eq 0 ]; then
	echo "usage: `basename $0` command" 1>&2
	exit 1
fi

LD_PRELOAD="@PREFIX@/lib/libtsocks.so"; export LD_PRELOAD
exec $*
