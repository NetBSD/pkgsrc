#!/bin/sh
#
# $NetBSD: innd.sh,v 1.3 1999/07/24 17:07:27 tron Exp $
#
if [ -x @@PREFIX@@/bin/rc.news -a -s @@INN_DATA_DIR@@/db/active ];
then
 su news @@PREFIX@@/bin/rc.news >/dev/null
 echo -n ' innd'
fi
exit 0
