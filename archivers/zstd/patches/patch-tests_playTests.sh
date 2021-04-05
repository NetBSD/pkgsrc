$NetBSD: patch-tests_playTests.sh,v 1.2 2021/04/05 10:12:38 ryoon Exp $

Fix md5 call on NetBSD.
Fix stat arguments on NetBSD.
https://github.com/facebook/zstd/issues/2493

--- tests/playTests.sh.orig	2021-03-02 22:20:57.000000000 +0000
+++ tests/playTests.sh
@@ -113,6 +113,7 @@ esac
 
 case "$UNAME" in
   Darwin) MD5SUM="md5 -r" ;;
+  NetBSD) MD5SUM="md5 -n" ;;
   FreeBSD) MD5SUM="gmd5sum" ;;
   NetBSD) MD5SUM="md5 -n" ;;
   OpenBSD) MD5SUM="md5" ;;
