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
    # * must be from a reasonably sized range
    # As of El Capitan, Apple use up to UID 252 for system accounts.

    used_uids=`nireport . /users uid 2>/dev/null ||			\
      dscl . -readall /users UniqueID | grep '^UniqueID:' | cut -d' ' -f2`
    low_uid=300; high_uid=499

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
if nireport . /users/$user uid 2>/dev/null ||				\
   dscl . -read /users/$user uid >/dev/null 2>&1; then
    echo "useradd: User '$user' already exists" 1>&2
    exit 1
fi

if [ -z "$group" ]; then
    echo "useradd: Must specify group name" 1>&2
    exit 1
fi
gid=`niutil -readprop . /groups/$group gid 2>/dev/null ||		\
     dscl . -read /groups/$group gid 2>/dev/null | cut -d' ' -f2`
if [ -z "$gid" -o "$gid" = "Invalid" ]; then
    echo "useradd: No group '$group'" 1>&2
    exit 1
fi

if [ -n "$uid" ]; then
    if nireport . /users/uid=$uid uid 2>/dev/null ||			\
      dscl . -search /users UniqueID $uid 2>/dev/null |		\
      grep UniqueID >/dev/null 2>&1 ; then
	echo "useradd: UID $uid already exists" 1>&2
	exit 1
    fi
else
    if ! uid=`getnextuid $gid`; then
        echo "useradd: no UIDs available in pkgsrc range" 1>&2
        exit 1
    fi
fi

if [ -x /usr/bin/niload ] || which niload | grep -v -q '^no '; then
    echo "${user}:*:${uid}:${gid}::0:0:${comment}:${homedir}:${shell}" | \
    niload passwd .
else
    dscl . -create /users/$user RecordName $user
    dscl . -create /users/$user RecordType dsRecTypeNative:users
    dscl . -create /users/$user UniqueID $uid
    dscl . -create /users/$user PrimaryGroupID $gid
    dscl . -create /users/$user NFSHomeDirectory "$homedir"
    dscl . -create /users/$user UserShell "$shell"
    dscl . -create /users/$user Comment "$comment"
    dscl . -delete /users/$user AuthenticationAuthority
    dscl . -create /users/$user Password '*'
    dscl . -create /users/$user IsHidden 1
fi

if ! nireport . /users/uid=$uid uid 2>/dev/null &&			\
   ! dscl . -search /users UniqueID $uid 2>/dev/null |			\
   grep UniqueID >/dev/null 2>&1 ; then
    echo "useradd: Could not create user" 1>&2
    exit 1
fi

kill -HUP `cat /var/run/lookupd.pid 2>/dev/null` 2>/dev/null || true
