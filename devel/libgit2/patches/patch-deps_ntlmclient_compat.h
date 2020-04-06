$NetBSD: patch-deps_ntlmclient_compat.h,v 1.2 2020/04/06 08:33:41 wiz Exp $

NetBSD does not have htonll.

--- deps/ntlmclient/compat.h.orig	2020-04-01 13:49:12.000000000 +0000
+++ deps/ntlmclient/compat.h
@@ -21,7 +21,7 @@
 # include <stdbool.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 /* See man page endian(3) */
 # include <endian.h>
 # define htonll htobe64
