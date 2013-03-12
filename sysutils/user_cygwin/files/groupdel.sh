#!/bin/bash
# $NetBSD: groupdel.sh,v 1.2 2013/03/12 05:41:39 obache Exp $

export PATH=/bin:"$(/bin/cygpath -S)"

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

run_cmd net localgroup $1 /delete || exit 1
/bin/sed -i -e "/^$1.*/d" /etc/group
