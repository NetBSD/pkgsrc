$NetBSD: patch-darwin.c,v 1.1 2021/03/18 22:54:52 khorben Exp $

Fix casting errors.

--- darwin.c.orig	2014-08-05 03:39:54.000000000 +0000
+++ darwin.c
@@ -79,7 +79,11 @@ sockwant(Socket *s, int rw)
             ev->data = Infinity;
         }
         ev->flags = EV_ADD;
-        ev->udata = s;
+#if defined(__NetBSD__)
+        ev->udata = (intptr_t) s;
+#else
+	ev->udata = s;
+#endif
         s->added = ev->filter;
         ev++;
         n++;
@@ -105,7 +109,11 @@ socknext(Socket **s, int64 timeout)
     }
 
     if (r > 0) {
-        *s = ev.udata;
+#if defined(__NetBSD__)
+        *s = (Socket *) ev.udata;
+#else
+	*s = ev.udata;
+#endif
         if (ev.flags & EV_EOF) {
             return 'h';
         }
