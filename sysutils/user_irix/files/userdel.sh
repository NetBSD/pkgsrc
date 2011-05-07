#!/bin/sh

show_usage () {
    echo "usage: userdel user" >&2
    exit 1
}

if test $# -ne 1; then
    show_usage
    exit 1
fi

eval "/usr/sbin/passmgmt -d $1"
