#!/bin/sh

if [ -x @PREFIX@/bin/upclient ]
then
	su -m nobody -c @PREFIX@/bin/upclient
	echo -n ' upclient'
fi
