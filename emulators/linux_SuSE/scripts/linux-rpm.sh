#!/bin/sh
#
# $Id: linux-rpm.sh,v 1.1.1.1 1998/10/31 00:18:47 tron Exp $

OPTS="--root @@EMULDIR@@"
for ARG
do
 if [ "$ARG" = "-i" ]
 then
  OPTS="$OPTS --ignoreos"
 fi
done

if [ `whoami` != root ]
then
 exec rpm $OPTS $*
fi

mkdir -p @@EMULDIR@@/var/tmp
cp -p /etc/spwd.db @@EMULDIR@@/etc
rpm $OPTS $*
RC=$?
rm -rf @@EMULDIR@@/etc/spwd.db @@EMULDIR@@/var/tmp

exit $RC
