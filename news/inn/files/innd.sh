#!/bin/sh
#
# $NetBSD: innd.sh,v 1.4 1999/07/24 17:38:14 tron Exp $
#
if [ -x @@PREFIX@@/bin/rc.news -a -s @@INN_DATA_DIR@@/db/active ];
then
 su news -c @@PREFIX@@/bin/rc.news >/dev/null
 echo -n ' innd'
fi
exit 0
