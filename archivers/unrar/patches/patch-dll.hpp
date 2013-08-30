$NetBSD: patch-dll.hpp,v 1.1 2013/08/30 10:16:58 wiz Exp $

NetBSD doesn't define _UNIX.

--- dll.hpp.orig	2013-08-30 09:33:40.000000000 +0000
+++ dll.hpp
@@ -36,7 +36,7 @@
 #define RAR_HASH_BLAKE2       2
 
 
-#ifdef _UNIX
+#if defined(_UNIX) || defined(__NetBSD__)
 #define CALLBACK
 #define PASCAL
 #define LONG long
