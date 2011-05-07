#!/bin/ksh

set -e

PATH=/bin:/sbin:/usr/bin:/usr/sbin:$PATH

GID=1000 # start search from

show_usage () {
    echo "usage: $0 [-ov] [-g gid] group" >&2
    exit 1
}

while getopts 'g:ov' f; do
    case $f in
	g)	gid="$OPTARG";;
	o)	reuse=1;;
	v)	;; # ignored
	\?)	show_usage;;
    esac
done
shift $(($OPTIND - 1))

get_unassigned_gid (){
    awk -F: -v gid="$GID" '
	{ h [$3] = 0 }
	END {while (gid in h){++gid}; print gid}' /etc/group
}

uniq_gid (){
    if ! awk -F: -v gid="$1" '$3 == gid {exit 1}' /etc/group; then
	echo "Can't add group: gid $1 is a duplicate" 1>&2
	exit 1
    fi
}

uniq_name (){
    if ! awk -F: -v name="$1" '$1 == name {exit 1}' /etc/group; then
	echo "Can't add group: $1 is a duplicate" 1>&2
	exit 1
    fi
}

if test $# -ne 1; then
    show_usage
fi

uniq_name "$1"

if test -z "$gid"; then
    gid=`get_unassigned_gid`
elif test -z "$reuse"; then
    uniq_gid "$gid"
fi

cp -p /etc/group /etc/group.tmp
echo "$1:*:$gid:" >> /etc/group.tmp
mv /etc/group.tmp /etc/group
