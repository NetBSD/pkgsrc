#! @SH@
set -eu

ldconf="@PREFIX@/lib/ocaml/ld.conf"
fgrep="@FGREP@"

usage() {
	echo "usage: $0 <add|del> directory" 1>&2
	exit 1
}

test $# = 2 || usage

action="$1"
dir="$2"

test "$action" = "add" || test "$action" = "del" || usage

$fgrep -v -- "$dir" < "${ldconf}" > "${ldconf}.tmp"
if test "$action" = "add"; then
	printf "%s\\n" "$dir" >> "${ldconf}.tmp"
fi
mv -f "${ldconf}.tmp" "${ldconf}"
