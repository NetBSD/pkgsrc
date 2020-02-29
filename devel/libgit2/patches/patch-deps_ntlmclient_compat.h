$NetBSD: patch-deps_ntlmclient_compat.h,v 1.1 2020/02/29 11:39:54 nia Exp $

NetBSD does not have htonll.

--- deps/ntlmclient/compat.h.orig	2020-02-19 10:27:00.000000000 +0000
+++ deps/ntlmclient/compat.h
@@ -21,7 +21,7 @@
 # include <stdbool.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 # include <endian.h>
 # define htonll htobe64
 #endif
