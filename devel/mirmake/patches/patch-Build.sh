$NetBSD: patch-Build.sh,v 1.1 2023/07/12 19:34:39 vins Exp $

pkgsrc PREFIX support.

--- Build.sh.orig	2014-12-20 22:14:21.000000000 +0000
+++ Build.sh
@@ -141,7 +141,7 @@ fi
 
 mktest=
 for f in mksh mirbsdksh ksh; do
-	for d in /usr/bin /usr/local/bin /bin /sw/bin; do
+	for d in @PREFIX@/bin /usr/bin /usr/local/bin /bin /sw/bin; do
 		mktest="${mktest}${d}/${f} "
 	done
 done
