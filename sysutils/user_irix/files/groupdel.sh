#!/bin/sh

PATH=/bin:/sbin:/usr/bin:/usr/sbin:$PATH

show_usage () {
    echo "usage: $0 [v] group" >&2
    exit 1
}

while getopts 'v' f; do
    case $f in
	v)	;; # ignored
	\?)	show_usage;;
    esac
done
shift $(($OPTIND - 1))

if test $# -ne 1; then
    show_usage
fi

cp -p /etc/group /etc/group.tmp
awk -F: -v name="$1" '$1 != name' /etc/group > /etc/group.tmp
mv /etc/group.tmp /etc/group
