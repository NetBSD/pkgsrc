#!/bin/sh

while [ $# -gt 1 ]; do
    case $1 in
	-g) gid="$2" ;;
	*) echo "groupadd: Unrecognized option $1" 1>&2; exit 1; ;;
    esac
    shift; shift
done

group="$1"
if [ -z "$group" ]; then
    echo "groupadd: Must specify group name" 1>&2
    exit 1
fi

if nireport . /groups/$group gid 2>/dev/null; then
    echo "groupadd: Group '$group' already exists" 1>&2
    exit 1
fi

if [ -n "$gid" ]; then
    if nireport . /groups/gid=$gid gid 2>/dev/null; then
	echo "groupadd: GID $gid already exists" 1>&2
	exit 1
    fi
else
    # Find a good unused gid. See the comments in useradd for
    # more details
    gid=300
    nireport . /groups gid | sort -n | while read used_gid; do
	if [ $gid = $used_gid ]; then
	    gid=`expr $gid + 1`
	fi
    done
fi

echo "${group}:*:${gid}:" | niload group .
if ! nireport . /groups/$group gid 2>/dev/null; then
    echo "groupadd: Could not create group" 1>&2
    exit 1
fi
