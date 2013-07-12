$NetBSD: patch-misc.h,v 1.1 2013/07/12 19:06:31 christos Exp $

Portable inlines are in header files.

--- misc.h.orig	2013-06-17 06:17:24.000000000 -0400
+++ misc.h	2013-07-12 14:58:05.000000000 -0400
@@ -65,7 +65,6 @@
 extern struct buffer *new_buf (int);
 extern void udppush_handler (int);
 extern int addfcs (struct buffer *buf);
-extern inline void swaps (void *, int);
 extern void do_packet_dump (struct buffer *);
 extern void status (const char *fmt, ...);
 extern void status_handler (int signal);
@@ -76,4 +75,30 @@
 extern void opt_destroy (struct ppp_opts *);
 extern struct ppp_opts *add_opt (struct ppp_opts *, char *, ...);
 extern void process_signal (void);
+
+
+static inline void swaps (void *buf_v, int len)
+{
+#ifdef __alpha
+    /* Reverse byte order alpha is little endian so lest save a step.
+       to make things work out easier */
+    int x;
+    unsigned char t1;
+    unsigned char *tmp = (_u16 *) buf_v;
+    for (x = 0; x < len; x += 2)
+    {
+        t1 = tmp[x];
+        tmp[x] = tmp[x + 1];
+        tmp[x + 1] = t1;
+    }
+#else
+
+    /* Reverse byte order (if proper to do so) 
+       to make things work out easier */
+    int x;
+    struct hw { _u16 s; } __attribute__((__packed__)) *p = (struct hw *) buf_v;
+    for (x = 0; x < len / 2; x++, p++)
+	    p->s = ntohs(p->s); 
+#endif
+}
 #endif
