$NetBSD: patch-misc.c,v 1.1 2013/07/12 19:06:31 christos Exp $

Declare inline in a separate file.

--- misc.c.orig	2013-06-17 06:17:24.000000000 -0400
+++ misc.c	2013-07-12 14:58:32.000000000 -0400
@@ -170,33 +170,6 @@
     printf ("}\n");
 }
 
-inline void swaps (void *buf_v, int len)
-{
-#ifdef __alpha
-    /* Reverse byte order alpha is little endian so lest save a step.
-       to make things work out easier */
-    int x;
-    unsigned char t1;
-    unsigned char *tmp = (_u16 *) buf_v;
-    for (x = 0; x < len; x += 2)
-    {
-        t1 = tmp[x];
-        tmp[x] = tmp[x + 1];
-        tmp[x + 1] = t1;
-    }
-#else
-
-    /* Reverse byte order (if proper to do so) 
-       to make things work out easier */
-    int x;
-	struct hw { _u16 s; } __attribute__ ((packed)) *p = (struct hw *) buf_v;
-	for (x = 0; x < len / 2; x++, p++)
-		p->s = ntohs(p->s); 
-#endif
-}
-
-
-
 inline void toss (struct buffer *buf)
 {
     /*
