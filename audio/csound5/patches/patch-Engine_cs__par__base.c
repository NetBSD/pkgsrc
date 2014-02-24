$NetBSD: patch-Engine_cs__par__base.c,v 1.1 2014/02/24 16:19:39 joerg Exp $

--- Engine/cs_par_base.c.orig	2014-02-24 12:54:12.000000000 +0000
+++ Engine/cs_par_base.c
@@ -547,34 +547,6 @@ int csp_set_print(CSOUND *csound, struct
     return CSOUND_SUCCESS;
 }
 
-inline int csp_set_count(struct set_t *set)
-{
-    return set->count;
-}
-
-/* 0 indexed */
-inline int csp_set_get_num(struct set_t *set, int num, void **data)
-{
-    *data = set->cache[num]->data;
-    /*
-    if (set->cache != NULL) {
-
-    }
-    else {
-    int ctr = 0;
-    struct set_element_t *ele = set->head;
-    while (ctr < num && ele != NULL) {
-    ctr++;
-    ele = ele->next;
-        }
-        if (ctr == num && ele != NULL) {
-            *data = ele->data;
-        }
-    }
-    */
-    return CSOUND_SUCCESS;
-}
-
 int csp_set_union(CSOUND *csound, struct set_t *first,
                   struct set_t *second, struct set_t **result)
 {
