#!/bin/sh

if [ -x @PREFIX@/bin/upclient ]
then
	@INSTALL@ -o nobody -m 644 /dev/null /var/run/upclient.pid
	@SU@ -m nobody -c @PREFIX@/bin/upclient >/dev/null
	echo -n ' upclient'
fi
