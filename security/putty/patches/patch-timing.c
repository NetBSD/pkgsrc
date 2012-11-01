$NetBSD: patch-timing.c,v 1.1 2012/11/01 19:32:44 joerg Exp $

--- timing.c.orig	2012-10-30 22:23:57.000000000 +0000
+++ timing.c
@@ -41,21 +41,10 @@ static int compare_timers(void *av, void
      * Failing that, compare on the other two fields, just so that
      * we don't get unwanted equality.
      */
-#ifdef __LCC__
-    /* lcc won't let us compare function pointers. Legal, but annoying. */
-    {
-	int c = memcmp(&a->fn, &b->fn, sizeof(a->fn));
-	if (c < 0)
-	    return -1;
-	else if (c > 0)
-	    return +1;
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
