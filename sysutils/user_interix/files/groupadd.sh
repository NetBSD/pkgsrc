#!/bin/ksh
# $NetBSD: groupadd.sh,v 1.2 2004/04/27 01:50:04 tv Exp $

export PATH=/bin:/usr/contrib/win32/bin

show_usage () {
	echo "usage: $0 [-v] group" >&2
	exit 1
}

verbose=false
run_cmd () {
	if $verbose; then printf '%s\n' "+ $*"; fi
	"$@"
}

while getopts 'g:ov' f; do
	case $f in
	g)	echo "$0: numeric gid cannot be set manually; ignoring" >&2;;
	o)	echo "$0: cannot reuse numeric gid of another group; aborting" >&2; exit 1;;
	v)	verbose=true;;
	\?)	show_usage;;
	esac
done
shift $(($OPTIND - 1))

if [ $# -ne 1 ]; then show_usage; fi
$verbose || exec >/dev/null

run_cmd net localgroup $1 /add /comment:"Group added by Interix groupadd command"
