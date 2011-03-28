$NetBSD: patch-ext_bigdecimal_bigdecimal.c,v 1.1 2011/03/28 16:19:36 taca Exp $

* Fix for CVE-2011-0188 from repository, r30993.

--- ext/bigdecimal/bigdecimal.c.orig	2010-05-08 02:07:43.000000000 +0000
+++ ext/bigdecimal/bigdecimal.c
@@ -2123,9 +2123,9 @@ static int gnAlloc=0; /* Memory allocati
 VP_EXPORT void *
 VpMemAlloc(U_LONG mb)
 {
-    void *p = xmalloc((unsigned int)mb);
-    if(!p) {
-        VpException(VP_EXCEPTION_MEMORY,"failed to allocate memory",1);
+    void *p = xmalloc(mb);
+    if (!p) {
+	VpException(VP_EXCEPTION_MEMORY, "failed to allocate memory", 1);
     }
     memset(p,0,mb);
 #ifdef BIGDECIMAL_DEBUG
