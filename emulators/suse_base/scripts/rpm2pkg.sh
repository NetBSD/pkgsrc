#!/bin/sh
export PATH=/bin:/usr/bin:@@PREFIX@@/bin

TMPDIR=/tmp/.rpm.$$.`date +%s`
PLIST=$TMPDIR/PLIST

if ! rm -rf $PLIST $TMPDIR
then 
 exit 1
fi
if ! mkdir -p $TMPDIR/@@EMULSUBDIR@@
then 
 exit 1
fi

for RPM
do
 rpm2cpio $RPM | (cd $TMPDIR/@@EMULSUBDIR@@; cpio -i -d 2>/dev/null)
done

(cd $TMPDIR
 find @@EMULSUBDIR@@/* -type f | sort
 find @@EMULSUBDIR@@/* -type d | sort | awk '{print("@exec mkdir -p %D/"$1)}'
 find @@EMULSUBDIR@@/* -type l | sort |
 (while read LINK
  do
   set - X `file $LINK`
   if cd `dirname $LINK` && test -f $6
   then
    echo $LINK
   else
    echo "@exec ln -s $6 %D/$LINK"
    echo "@unexec rm -f %D/$LINK"
   fi
   cd $TMPDIR
  done)
 find @@EMULSUBDIR@@/* -type d | sort -r |
 awk '{print("@unexec rmdir %D/"$1" >/dev/null 2>&1 || true")}') >$PLIST

@@GTAR@@ cCf $TMPDIR - @@EMULSUBDIR@@ | @@GTAR@@ xCf @@PREFIX@@ -

cat $PLIST

rm -rf $TMPDIR
exit 0

