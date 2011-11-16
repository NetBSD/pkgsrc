$NetBSD: patch-client_xymonclient-netbsd.sh,v 1.1 2011/11/16 21:45:01 spz Exp $

add to filesystems whose 'level of filling' is uninteresting

--- client/xymonclient-netbsd.sh.orig	2011-07-31 21:01:52.000000000 +0000
+++ client/xymonclient-netbsd.sh
@@ -20,7 +20,7 @@ uptime
 echo "[who]"
 who
 echo "[df]"
-df -P -tnonfs,kernfs,procfs,cd9660,null | sed -e '/^[^ 	][^ 	]*$/{
+df -P -tnonfs,kernfs,procfs,cd9660,null,ptyfs,fdesc | sed -e '/^[^ 	][^ 	]*$/{
 N
 s/[ 	]*\n[ 	]*/ /
 }'
