#!/bin/sh
#
# $NetBSD: rtspd.sh,v 1.2 1999/09/03 13:52:17 tron Exp $
#
if [ -x @PREFIX@/sbin/rtspd ]
then
 @PREFIX@/sbin/rtspd
 echo -n ' rtspd'
fi
exit 0
