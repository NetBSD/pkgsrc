#!/bin/sh
#
# $NetBSD: innd.sh,v 1.1 1999/07/21 20:38:56 tron Exp $
#
if [ -x @@PREFIX@@/bin/inndstart -a -s @@INN_DATA_DIR@@/db/active ];
then
 @@PREFIX@@/bin/inndstart >/dev/null 2>&1
 echo -n ' innd'
fi
exit 0
