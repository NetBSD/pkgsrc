#!/bin/sh
#
# $NetBSD: rtspd.sh,v 1.1.1.1 1999/09/01 20:25:03 tron Exp $
#
if [ -x @PREFIX@/sbin/rtspd
then
 @PREFIX@/sbin/rtspd
 echo -n ' rtspd'
fi
exit 0
