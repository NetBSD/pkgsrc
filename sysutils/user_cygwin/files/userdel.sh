#!/bin/bash
# $NetBSD: userdel.sh,v 1.4 2013/03/13 12:35:16 obache Exp $

export PATH=/bin:"$(/bin/cygpath -S)"

show_usage () {
	echo "usage: $0 [-rv] user" >&2
	exit 1
}

verbose=false
run_cmd () {
	if $verbose; then printf '%s\n' "+ $*" >&2; fi
	"$@"
}

remove_home_dir=false
user_is_group=false

while getopts 'prv' f; do
	case $f in
	p)	echo "$0: cannot yet lock out user with -p; aborting" >&2; exit 1;;
	r)	remove_home_dir=true;;
	v)	verbose=true;;
	\?)	show_usage;;
	esac
done
shift $(($OPTIND - 1))

if [ $# -ne 1 ]; then show_usage; fi
$verbose || exec >/dev/null

if ! net user $1 >/dev/null 2>&1; then
	if ! net localgroup $1 >/dev/null 2>&1; then
		echo "$0: user $1 does not exist" >&2; exit 1
	else
		user_is_group=true
	fi
fi

if $remove_home_dir; then
	home_dir="$(eval "echo ~$1")"

	case "$home_dir" in
	/)	echo "$0: user $1 has no home directory; ignoring remove request" >&2;;
	/*/*)	rm -rf "$home_dir";;
	*)	echo "$0: could not delete home directory '$home_dir'; aborting" >&2; exit 1;;
	esac
fi

$user_is_group || run_cmd net user $1 /delete || exit 1
/bin/sed -i -e "/^$1.*/d" /etc/passwd
