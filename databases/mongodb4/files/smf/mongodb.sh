#!/bin/bash
#
# SMF method for svc:/pkgsrc/mongodb:default

. /lib/svc/share/smf_include.sh

# mongodb doesn't really work with anything else but C locale
export LANG=C

PATH="@PREFIX@/bin:@PREFIX@/gnu/bin:@PREFIX@/sbin:/usr/bin:/usr/sbin";
MONGO_DBPATH="@MONGODB_DBPATH@";
MONGO_CONF="@PKG_SYSCONFDIR@/mongod.conf";
MONGO_PID="${MONGO_DBPATH}/mongod.pid";

case "$1" in
        'start')
                mongod --fork -f ${MONGO_CONF} --pidfilepath ${MONGO_PID}
                ;;

        'stop')
                [[ -s ${MONGO_PID} ]] && kill $(cat ${MONGO_PID}) 2>/dev/null
                ;;

        'restart')
                [[ -s ${MONGO_PID} ]] && kill $(cat ${MONGO_PID}) 2>/dev/null
                sleep 3;
                mongod --fork -f ${MONGO_CONF} --pidfilepath ${MONGO_PID}
                ;;
        *)
                echo "usage: $0 { start | stop | restart }"
                exit 1;
                ;;
esac
