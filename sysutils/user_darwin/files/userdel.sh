#!/bin/sh

if [ $# -gt 1 ]; then
    echo "userdel: Unrecognized option $1" 1>&2
    exit 1
fi

user="$1"
if [ -z "$user" ]; then
    echo "userdel: Must specify username" 1>&2
    exit 1
fi

if ! niutil -destroy . /users/$user 2>/dev/null; then
    echo "userdel: Could not delete user" 1>&2
    exit 1
fi
