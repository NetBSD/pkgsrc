#!/bin/sh
#
# $NetBSD: innd.sh,v 1.7 1999/07/29 21:15:46 tron Exp $
#
if [ -x @@PREFIX@@/inn/bin/rc.news -a -s @@INN_DATA_DIR@@/db/active ];
then
 su news -c @@PREFIX@@/inn/bin/rc.news >/dev/null

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
