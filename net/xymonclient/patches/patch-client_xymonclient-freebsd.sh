$NetBSD: patch-client_xymonclient-freebsd.sh,v 1.1 2022/01/06 11:53:26 hauke Exp $

Add linsysfs to filesystems whose 'level of filling' is uninteresting

--- client/xymonclient-freebsd.sh.orig	2015-12-16 15:13:03.000000000 +0000
+++ client/xymonclient-freebsd.sh
@@ -22,13 +22,13 @@ echo "[who]"
 who
 echo "[df]"
 # The sed stuff is to make sure lines are not split into two.
-df -H -tnonfs,nullfs,cd9660,procfs,devfs,linprocfs,fdescfs | sed -e '/^[^ 	][^ 	]*$/{
+df -H -tnonfs,nullfs,cd9660,procfs,devfs,linprocfs,linsysfs,fdescfs | sed -e '/^[^ 	][^ 	]*$/{
 N
 s/[ 	]*\n[ 	]*/ /
 }'
 echo "[inode]"
 # The sed stuff is to make sure lines are not split into two.
-df -i -tnonfs,nullfs,cd9660,procfs,devfs,linprocfs,fdescfs | sed -e '/^[^ 	][^ 	]*$/{
+df -i -tnonfs,nullfs,cd9660,procfs,devfs,linprocfs,linsysfs,fdescfs | sed -e '/^[^ 	][^ 	]*$/{
 N
 s/[ 	]*\n[ 	]*/ /
 }' | awk '
