$NetBSD: patch-sqlite3_stubs.c,v 1.2 2012/09/01 12:48:10 marino Exp $

Avoiding redefinition of __unused on NetBSD and DragonFly

--- sqlite3_stubs.c.orig	2008-04-13 14:26:56.000000000 +0200
+++ sqlite3_stubs.c	2008-04-13 14:27:35.000000000 +0200
@@ -40,7 +40,7 @@
 
 #if __GNUC__ >= 3
 # define inline inline __attribute__ ((always_inline))
-# if !defined(__FreeBSD__) && !__APPLE__
+# if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__) && !__APPLE__
 # define __unused __attribute__ ((unused))
 # endif
 #else
