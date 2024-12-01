#!/bin/sh

# On startup, there is a hang (not understood).  This script attempts
# to identify and kill any such hung processes.  The normal process
# supervision restarts it, and it seems the second time it doesn't
# hang.

while sleep 60; do
    pids=`ps uaxw | egrep 'zmdc.pl start ' | egrep -v egrep | awk '{print $2}'`
    if [ "$pids" != "" ]; then
	logger "$0: found $pids"
	sleep 10
	for p in $pids; do
	    if kill -0 $p 2> /dev/null; then
		logger "$0: pid $p still alive"
		kill $p
	    fi
	done
    fi
done
