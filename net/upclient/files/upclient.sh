#!/bin/sh

pidfile=/var/run/upclient.pid

if [ "$1" = "stop" ]; then
	kill `cat $pidfile`

else
	if [ -x @PREFIX@/bin/upclient ]
	then
		@INSTALL@ -o nobody -m 644 /dev/null $pidfile
		@SU@ -m nobody -c @PREFIX@/bin/upclient
		echo -n ' upclient'
	fi
fi
