$NetBSD: patch-timing.c,v 1.3 2019/10/01 15:22:41 ryoon Exp $

--- timing.c.orig	2019-09-22 09:14:51.000000000 +0000
+++ timing.c
@@ -60,19 +60,10 @@ static int compare_timers(void *av, void
      * Failing that, compare on the other two fields, just so that
      * we don't get unwanted equality.
      */
-#if defined(__LCC__) || defined(__clang__)
-    /* lcc won't let us compare function pointers. Legal, but annoying. */
-    {
-        int c = memcmp(&a->fn, &b->fn, sizeof(a->fn));
-        if (c)
-            return c;
-    }
-#else
-    if (a->fn < b->fn)
+    if ((uintptr_t)a->fn < (uintptr_t)b->fn)
         return -1;
-    else if (a->fn > b->fn)
+    else if ((uintptr_t)a->fn > (uintptr_t)b->fn)
         return +1;
-#endif
 
     if (a->ctx < b->ctx)
         return -1;
