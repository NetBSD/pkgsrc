#!/bin/sh

if [ -x @PREFIX@/bin/upclient ]
then
	@PREFIX@/bin/upclient
	echo -n ' upclient'
fi
