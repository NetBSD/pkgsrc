#!/bin/sh

PATH=/bin:/usr/bin:$PATH

while [ $# -gt 1 ]; do
    case $1 in
	-g) gid="$2" ;;
	*) echo "groupadd: Unrecognized option $1" 1>&2; exit 1; ;;
    esac
    shift; shift
done

getnextgid()
{
    # See the comments in useradd for more details.

    used_gids=`nireport . /groups gid`
    low_gid=300

    maybe_gid=$low_gid
    while true; do
        if echo $used_gids | grep -q $maybe_gid; then
            maybe_gid=`expr $maybe_gid + 1`
        else
            echo $maybe_gid
            return 0
        fi
    done
}

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
    gid=`getnextgid`
fi

echo "${group}:*:${gid}:" | niload group .
if ! nireport . /groups/$group gid 2>/dev/null; then
    echo "groupadd: Could not create group" 1>&2
    exit 1
fi
