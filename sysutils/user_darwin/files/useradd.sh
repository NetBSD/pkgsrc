#!/bin/sh

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
    # Find an unused uid, using the gid as the default value if it's
    # not already being used. Assuming this is a system account, not
    # a user account, we want a UID less than 500, so OS X won't
    # display it in the login window or the Accounts preference pane.
    # Apple seems to be using UIDs and GIDs below (but approaching) 100,
    # and fink uses UIDs starting with 400, so we'll use the 300s.

    uid=$gid
    if [ $uid -lt 300 ]; then
	uid=300
    fi
    nireport . /users uid | sort -n | while read used_uid; do
	if [ $uid = $used_uid ]; then
	    uid=`expr $uid + 1`
	fi
    done
fi

echo "${user}:*:${uid}:${gid}::0:0:${comment}:${homedir}:${shell}" | niload passwd .
if ! nireport . /users/$user uid 2>/dev/null; then
    echo "useradd: Could not create user" 1>&2
    exit 1
fi
