#!/bin/sh

PATH=/bin:/usr/bin:$PATH

homedir="/var/empty"
shell="/usr/bin/false"

while [ $# -gt 1 ]; do
    case $1 in
	-c) comment="$2" ;; 
	-d) homedir="$2" ;;
	-g) group="$2"   ;;
	-s) shell="$2"   ;;
	-u) uid="$2"     ;;
	*) echo "useradd: Unrecognized option $1" 1>&2; exit 1; ;;
    esac
    shift; shift
done

getnextuid()
{
    # Find an unused UID. Constraints:
    # * must be <500 (typical OS X user accounts are 500 and up)
    # * must be <400 (Fink uses 400 and up)
    # * must be from a reasonably sized range

    used_uids=`nireport . /users uid`
    low_uid=300; high_uid=399

    # Try to use the GID as the UID.
    maybe_uid=$1
    if [ $maybe_uid -ge $low_uid ] && [ $maybe_uid -le $high_uid ] && \
      ! echo $used_uids | grep -q $maybe_uid; then
        echo $maybe_uid
        return 0
    fi

    # Else, walk the pkgsrc-"allocated" range.
    maybe_uid=$low_uid
    while [ $maybe_uid -le $high_uid ]; do
        if echo $used_uids | grep -q $maybe_uid; then
            maybe_uid=`expr $maybe_uid + 1`
        else
            echo $maybe_uid
            return 0
        fi
    done
    return 1
}

user="$1"
if [ -z "$user" ]; then
    echo "useradd: Must specify username" 1>&2
    exit 1
fi
if nireport . /users/$user uid 2>/dev/null; then
    echo "useradd: User '$user' already exists" 1>&2
    exit 1
fi

if [ -z "$group" ]; then
    echo "useradd: Must specify group name" 1>&2
    exit 1
fi
gid=`niutil -readprop . /groups/$group gid 2>/dev/null`
if [ -z "$gid" ]; then
    echo "useradd: No group '$group'" 1>&2
    exit 1
fi

if [ -n "$uid" ]; then
    if nireport . /users/uid=$uid uid 2>/dev/null; then
	echo "useradd: UID $uid already exists" 1>&2
	exit 1
    fi
else
    if ! uid=`getnextuid $gid`; then
        echo "useradd: no UIDs available in pkgsrc range" 1>&2
        exit 1
    fi
fi

echo "${user}:*:${uid}:${gid}::0:0:${comment}:${homedir}:${shell}" | niload passwd .
if ! nireport . /users/$user uid 2>/dev/null; then
    echo "useradd: Could not create user" 1>&2
    exit 1
fi

kill -HUP `cat /var/run/lookupd.pid`
