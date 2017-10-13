$NetBSD: patch-misc.c,v 1.2 2017/10/13 17:24:05 christos Exp $

Declare inline in a separate file.

--- misc.c.orig	2017-08-02 13:46:06.000000000 -0400
+++ misc.c	2017-10-13 12:51:24.225866762 -0400
@@ -175,33 +175,6 @@
     printf ("}\n");
 }
 
-void swaps (void *buf_v, int len)
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
