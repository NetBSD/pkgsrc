#!/bin/sh
export PATH=/bin:/usr/bin:@@PREFIX@@/bin

TMPDIR=/tmp/.rpm.$$.`date +%s`
LIST=$TMPDIR/LIST
DIRS=$TMPDIR/DIRS
FILES=$TMPDIR/FILES
LINKS=$TMPDIR/LINKS

if ! rm -rf $TMPDIR
then 
 exit 1
fi
if ! mkdir -p $TMPDIR/@@EMULSUBDIR@@
then 
 exit 1
fi

touch $LIST
for RPM
do
 rpm2cpio $RPM | (cd @@EMULDIR@@; @@PAX@@ -r -v 2>>$LIST)
done

touch $DIRS $LINKS
cd @@PREFIX@@
grep -v ^pax:\  $LIST | @@AWK@@ '{print("@@EMULSUBDIR@@/"$1)}' |
(while read ENTRY
 do
  if [ -L "$ENTRY" ]
  then
   set - `file $ENTRY`
   shift `expr $# - 1`;
   case $1 in
   /* )
    set - @@EMULDIR@@$1
    rm $ENTRY
    ln -s $1 $ENTRY
    ;;
   esac
   if cd `dirname $ENTRY` && test -f $1
   then
    echo $ENTRY
   else
    echo "@exec ln -s $1 %D/$ENTRY" >>$LINKS
    echo "@unexec rm -f %D/$ENTRY" >>$LINKS
   fi
   cd @@PREFIX@@
  else
   if [ -f "$ENTRY" ]
   then
    echo "$ENTRY"
   else
    if [ -d "$ENTRY" ]
    then
     echo "$ENTRY" >>$DIRS
    fi
   fi
  fi
 done) >$FILES

cat $FILES
sort $DIRS | awk '{print("@exec mkdir -p %D/"$1)}'
cat $LINKS
sort -r $DIRS | awk '{print("@unexec rmdir %D/"$1" >/dev/null 2>&1 || true")}'

rm -rf $TMPDIR
exit 0
