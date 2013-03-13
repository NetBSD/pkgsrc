#!/bin/bash
# $NetBSD: groupadd.sh,v 1.3 2013/03/13 12:35:16 obache Exp $

export PATH=/bin:"$(/bin/cygpath -S)"

show_usage () {
	echo "usage: $0 [-v] group" >&2
	exit 1
}

verbose=false
run_cmd () {
	if $verbose; then printf '%s\n' "+ $*" >&2; fi
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
run_cmd /bin/mkgroup -l -g "$1" >> /etc/group || exit 1
