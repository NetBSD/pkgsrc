$NetBSD: patch-agm.h,v 1.1 2016/07/27 20:37:27 kamil Exp $

Fix K&R code.

--- agm.h.orig	2016-07-27 20:12:55.337407545 +0000
+++ agm.h
@@ -134,5 +134,15 @@ extern struct wnode *lstart, *lend;
 extern char main_RCSid[], gobble_RCSid[], listfuncs_RCSid[], output_RCSid[],
             process_RCSid[], sort_RCSid[], wordfuncs_RCSid[], progress_RCSid[];
 
-extern void copysmall();
-extern void arm_timer(), disarm_timer();
+extern void copysmall(char *, char *);
+extern void arm_timer(void), disarm_timer(void);
+extern int contains (char *, char *, unsigned int *);
+extern int addword (char *, struct wnode **, struct wnode **);
+extern int eliminate (char *, char *, char *);
+extern void print_prevs (int);
+extern void destroy_list (struct wnode *, struct wnode *);
+extern void gobble_file (char *, char *);
+extern void merge_sort (struct wnode **, int);
+extern void list_dictionary (struct wnode *);
+extern void minus_process (char *, char *);
+extern void process (char *, struct wnode *, struct wnode *, unsigned int, unsigned int, unsigned int);
