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

    used_gids=`nireport . /groups gid 2>/dev/null ||			\
      dscl . -readall /groups PrimaryGroupID  | grep '^PrimaryGroupID:' | \
      cut -d' ' -f2`
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

if nireport . /groups/$group gid 2>/dev/null ||				\
   dscl . -read /groups/$group gid >/dev/null 2>&1; then
    echo "groupadd: Group '$group' already exists" 1>&2
    exit 1
fi

if [ -n "$gid" ]; then
    if nireport . /groups/gid=$gid gid 2>/dev/null ||			\
      dscl . -search /groups PrimaryGroupID $gid 2>/dev/null |		\
      grep PrimaryGroupID >/dev/null 2>&1 ; then
	echo "groupadd: GID $gid already exists" 1>&2
	exit 1
    fi
else
    gid=`getnextgid`
fi

if [ -x /usr/bin/niload ] || which niload | grep -v -q '^no '; then
    echo "${group}:*:${gid}:" | niload group .
else
    dscl . -create /groups/$group RecordName $group
    dscl . -create /groups/$group RecordType dsRecTypeNative:groups
    dscl . -create /groups/$group PrimaryGroupID $gid
fi
if ! nireport . /groups/$group gid 2>/dev/null &&			\
   ! dscl . -search /groups PrimaryGroupID $gid 2>/dev/null |		\
   grep PrimaryGroupID >/dev/null 2>&1 ; then
    echo "groupadd: Could not create group $gid: $group" 1>&2
    exit 1
fi
