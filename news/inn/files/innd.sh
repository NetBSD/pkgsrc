#!/bin/sh
#
# $NetBSD: innd.sh,v 1.5 1999/07/26 20:56:24 tron Exp $
#
if [ -x @@PREFIX@@/bin/rc.news -a -s @@INN_DATA_DIR@@/db/active ];
then
 su news -c @@PREFIX@@/bin/rc.news >/dev/null

 if [ ! -f @@PREFIX@@/etc/nntp/server ]
 then
  hostname >@@PREFIX@@/etc/nntp/server
 fi

 if [ ! -f @@PREFIX@@/etc/nntp/domainname ]
 then
  set - X `grep -w ^fromhost: @@INN_DATA_DIR@@/etc/inn.conf | head -1`
  if [ $# -eq 3 ]
  then
   echo $3 >@@PREFIX@@/etc/nntp/domainname
  fi
 fi

 echo -n ' innd'
fi
exit 0
