$NetBSD: patch-libxorp_ipvxnet.hh,v 1.1 2020/04/17 00:20:45 joerg Exp $

--- libxorp/ipvxnet.hh.orig	2020-04-16 14:35:42.344739235 +0000
+++ libxorp/ipvxnet.hh
@@ -54,7 +54,7 @@ inline void
 IPNet<IPvX>::initialize_from_string(const char *cp)
     throw (InvalidString, InvalidNetmaskLength)
 {
-    char *slash = strrchr(cp, '/');
+    const char *slash = strrchr(cp, '/');
     if (slash == 0) xorp_throw(InvalidString, "Missing slash");
 
     if (*(slash + 1) == 0)
