$NetBSD: patch-ext_bigdecimal_bigdecimal.c,v 1.1 2011/05/29 01:36:24 taca Exp $

* Fix for CVE-2011-0188 from repository, r30993.

--- ext/bigdecimal/bigdecimal.c.orig	2010-06-08 07:49:18.000000000 +0000
+++ ext/bigdecimal/bigdecimal.c
@@ -2032,9 +2032,9 @@ static int gnAlloc=0; /* Memory allocati
 VP_EXPORT void *
 VpMemAlloc(U_LONG mb)
 {
-    void *p = xmalloc((unsigned int)mb);
-    if(!p) {
-        VpException(VP_EXCEPTION_MEMORY,"failed to allocate memory",1);
+    void *p = xmalloc(mb);
+    if (!p) {
+        VpException(VP_EXCEPTION_MEMORY, "failed to allocate memory", 1);
     }
     memset(p,0,mb);
 #ifdef _DEBUG
