#!/bin/sh
PREFIX=${PREFIX-@prefix@}

if [ -x ${PREFIX}/sbin/zhm -a -f ${PREFIX}/etc/zephyr/server.list ] ; then
     PATH=${PREFIX}/sbin:${PREFIX}/bin:$PATH ; export PATH
     zhm `cat ${PREFIX}/etc/zephyr/server.list` && echo -n ' zhm'
fi
