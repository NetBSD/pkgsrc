#!/bin/ksh
# $NetBSD: groupdel.sh,v 1.1.1.1 2004/04/27 01:45:22 tv Exp $

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

while getopts 'v' f; do
	case $f in
	v)	verbose=true;;
	\?)	show_usage;;
	esac
done
shift $(($OPTIND - 1))

if [ $# -ne 1 ]; then show_usage; fi
$verbose || exec >/dev/null

run_cmd net localgroup $1 /delete
