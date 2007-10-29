#!/bin/sh

PATH=/bin:/usr/bin:$PATH

if [ $# -gt 1 ]; then
    echo "groupdel: Unrecognized option $1" 1>&2
    exit 1
fi

group="$1"
if [ -z "$group" ]; then
    echo "groupdel: Must specify group" 1>&2
    exit 1
fi

if ! niutil -destroy . /groups/$group 2>/dev/null &&			\
   ! dscl . -delete /groups/$group >/dev/null 2>&1 ; then
    echo "groupdel: Could not delete group" 1>&2
    exit 1
fi
