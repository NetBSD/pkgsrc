$NetBSD: patch-tests_playTests.sh,v 1.1 2021/02/27 16:40:59 wiz Exp $

Fix md5 call on NetBSD.
Fix stat arguments on NetBSD.
https://github.com/facebook/zstd/issues/2493

--- tests/playTests.sh.orig	2020-12-19 00:39:42.000000000 +0000
+++ tests/playTests.sh
@@ -113,6 +113,7 @@ esac
 
 case "$UNAME" in
   Darwin) MD5SUM="md5 -r" ;;
+  NetBSD) MD5SUM="md5 -n" ;;
   FreeBSD) MD5SUM="gmd5sum" ;;
   OpenBSD) MD5SUM="md5" ;;
   *) MD5SUM="md5sum" ;;
@@ -120,7 +121,7 @@ esac
 
 MTIME="stat -c %Y"
 case "$UNAME" in
-    Darwin | FreeBSD | OpenBSD) MTIME="stat -f %m" ;;
+    Darwin | FreeBSD | OpenBSD | NetBSD) MTIME="stat -f %m" ;;
 esac
 
 DIFF="diff"
