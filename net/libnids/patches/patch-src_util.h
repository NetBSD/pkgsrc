$NetBSD: patch-src_util.h,v 1.1 2012/04/17 17:45:36 joerg Exp $

--- src/util.h.orig	2012-04-16 22:20:32.000000000 +0000
+++ src/util.h
@@ -23,9 +23,19 @@ struct lurker_node {
 
 void nids_no_mem(char *);
 char *test_malloc(int);
-inline int before(u_int seq1, u_int seq2);
-inline int after(u_int seq1, u_int seq2);
 void register_callback(struct proc_node **procs, void (*x));
 void unregister_callback(struct proc_node **procs, void (*x));
 
+static inline int
+before(u_int seq1, u_int seq2)
+{
+  return ((int)(seq1 - seq2) < 0);
+}
+
+static inline int
+after(u_int seq1, u_int seq2)
+{
+  return ((int)(seq2 - seq1) < 0);
+}
+
 #endif /* _NIDS_UTIL_H */
