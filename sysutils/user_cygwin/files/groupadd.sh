#!/bin/bash
# $NetBSD: groupadd.sh,v 1.2 2013/03/12 05:41:39 obache Exp $

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

run_cmd net localgroup $1 /add /comment:"Group added by Cygwin groupadd command" || exit 1
### regenerate cygwin /etc/group
(/bin/flock -x -n 9 || exit 1; /bin/mkgroup -l -g "$1" >&9 ) 9>> /etc/group
