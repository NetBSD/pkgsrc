$NetBSD: patch-H_cs__par__base.h,v 1.1 2014/02/24 16:19:39 joerg Exp $

--- H/cs_par_base.h.orig	2014-02-24 12:55:11.000000000 +0000
+++ H/cs_par_base.h
@@ -167,9 +167,33 @@ int csp_set_remove(CSOUND *csound,  stru
 int csp_set_exists(CSOUND *csound,  struct set_t *set, void *data);
 int csp_set_print(CSOUND *csound, struct set_t *set);
 
-/* get a count and access members */
-inline int csp_set_count(struct set_t *set);
-inline int csp_set_get_num(struct set_t *set, int num, void **data);
+static inline int csp_set_count(struct set_t *set)
+{
+    return set->count;
+}
+
+/* 0 indexed */
+static inline int csp_set_get_num(struct set_t *set, int num, void **data)
+{
+    *data = set->cache[num]->data;
+    /*
+    if (set->cache != NULL) {
+
+    }
+    else {
+    int ctr = 0;
+    struct set_element_t *ele = set->head;
+    while (ctr < num && ele != NULL) {
+    ctr++;
+    ele = ele->next;
+        }
+        if (ctr == num && ele != NULL) {
+            *data = ele->data;
+        }
+    }
+    */
+    return CSOUND_SUCCESS;
+}
 
 /* 
  * set union and intersection
