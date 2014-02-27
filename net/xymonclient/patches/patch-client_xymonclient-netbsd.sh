$NetBSD: patch-client_xymonclient-netbsd.sh,v 1.2 2014/02/27 20:22:41 spz Exp $

add to filesystems whose 'level of filling' is uninteresting
add an inode check

--- client/xymonclient-netbsd.sh.orig	2011-07-31 21:01:52.000000000 +0000
+++ client/xymonclient-netbsd.sh
@@ -20,7 +20,12 @@ uptime
 echo "[who]"
 who
 echo "[df]"
-df -P -tnonfs,kernfs,procfs,cd9660,null | sed -e '/^[^ 	][^ 	]*$/{
+df -P -tnonfs,kernfs,procfs,cd9660,null,ptyfs,fdesc | sed -e '/^[^ 	][^ 	]*$/{
+N
+s/[ 	]*\n[ 	]*/ /
+}'
+echo "[inode]"
+df -i -tnonfs,kernfs,procfs,cd9660,null,ptyfs,fdesc | sed -e '/^[^ 	][^ 	]*$/{
 N
 s/[ 	]*\n[ 	]*/ /
 }'
