#!/bin/ksh
# $NetBSD: useradd.sh,v 1.1.1.1 2004/04/27 01:45:22 tv Exp $

export PATH=/bin:/usr/contrib/win32/bin

show_usage () {
	echo "usage: $0 [-mv] [-G secondary-group] [-b base-dir] [-c comment] [-d home-dir] [-g group|=uid] user" >&2
	echo "       $0 -D" >&2
	exit 1
}

verbose=false
run_cmd () {
	if $verbose; then printf '%s\n' "+ $*"; fi
	"$@"
}

if [ "$USERPROFILE" != "" ]; then
	base_dir="$(dirname "$(ntpath2posix -c "$USERPROFILE")")"
else
	base_dir="/home"
fi

set -A extra_groups
create_homedir=false
gecos=
group=+Users
home_dir=

show_defaults () {
	printf 'base_dir\t%s\n' "$base_dir"
	printf 'comment\t\t%s\n' "$gecos"
	printf 'group\t\t%s\n' "$group"
	exit 0
}

while getopts 'DG:L:b:c:d:e:f:g:k:mp:or:s:u:v' f; do
	case $f in
	D)	show_defaults;;
	G)	extra_groups[${#extra_groups}]="$OPTARG";;
	L)	echo "$0: login classes not supported; ignoring" >&2;;
	b)	base_dir="$OPTARG";;
	c)	gecos="$OPTARG";;
	d)	home_dir="$OPTARG";;
	e)	echo "$0: expiry time not yet supported; ignoring" >&2;;
	f)	echo "$0: inactive time not yet supported; ignoring" >&2;;
	g)	group="$OPTARG";;
	k)	echo "$0: skeleton files not yet supported; ignoring" >&22;;
	m)	create_homedir=true;;
	p)	echo "$0: cannot set password from command line; aborting" >&2; exit 1;;
	o)	echo "$0: cannot reuse numeric uid of another user; aborting" >&2; exit 1;;
	r)	echo "$0: numeric ID range cannot be set manually; ignoring" >&2;;
	s)	echo "$0: setting login shell not yet supported; ignoring" >&2;;
	u)	echo "$0: numeric uid cannot be set manually; ignoring" >&2;;
	v)	verbose=true;;
	\?)	show_usage;;
	esac
done
shift $(($OPTIND - 1))

if [ $# -ne 1 ]; then show_usage; fi
$verbose || exec >/dev/null

### check for existence of desired groups

if [ "$group" != "=uid" ]; then
	if ! net localgroup "${group#+}" >/dev/null 2>&1; then
		echo "$0: group '$group' does not exist" >&2; exit 1
	fi
fi

for g in "${extra_groups[@]}"; do
	if ! net localgroup "${g#+}" >/dev/null 2>&1; then
		echo "$0: group '$g' does not exist" >&2; exit 1
	fi
done

### check for ability to create homedir

if $create_homedir && [ "$home_dir" = "" ]; then
	if [ ! -d "$base_dir" ]; then
		echo "$0: base dir '$base_dir' does not exist" >&2; exit 1
	fi

	home_dir="$base_dir/$1"
fi

if $create_homedir && [ -d "$home_dir" ]; then
	echo "$0: home dir '$home_dir' already exists; not clobbering" >&2
	create_homedir=false
fi

### add the user

run_cmd net user $1 /add /fullname:"$gecos" /comment:"User added by Interix useradd command" || exit 1

### put user in groups

if [ "${group#+}" != "Users" ]; then
	# "Users" added by default; remove and add the real one here:
	run_cmd net localgroup "Users" $1 /delete || exit 1

	# Under Interix, a user *is* a group.  Do nothing if =uid is given.
	if [ "$group" != "=uid" ]; then
		run_cmd net localgroup "${group#+}" $1 /add || exit 1
	fi
fi

for g in "${extra_groups[@]}"; do
	# Don't add a "primary" group as a "secondary" group too.
	if [ "${g#+}" != "${group#+}" ]; then
		run_cmd net localgroup "${g#+}" $1 /add || exit 1
	fi
done

### set, and optionally create and cacls the homedir

if [ "$home_dir" != "" ]; then
	home_dir_nt="$(posixpath2nt "$home_dir")"

	if $create_homedir; then
		# To get "vanilla" ACLs, we use Win32 "mkdir".
		run_cmd wmkdir "$home_dir_nt" || exit 1

		echo y | run_cmd cacls "$home_dir_nt" /T /G Administrators:F || exit 1
		run_cmd cacls "$home_dir_nt" /T /E /G SYSTEM:F || exit 1
		run_cmd cacls "$home_dir_nt" /T /E /G "$1":F || exit 1
	fi

	run_cmd net user "$1" /homedir:"$home_dir_nt" || exit 1
fi
