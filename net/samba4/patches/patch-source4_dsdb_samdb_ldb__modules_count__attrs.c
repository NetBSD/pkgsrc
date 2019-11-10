$NetBSD: patch-source4_dsdb_samdb_ldb__modules_count__attrs.c,v 1.1 2019/11/10 17:02:34 adam Exp $

Fix for systems without __compar_fn_t.

--- source4/dsdb/samdb/ldb_modules/count_attrs.c.orig	2019-11-09 22:30:59.000000000 +0000
+++ source4/dsdb/samdb/ldb_modules/count_attrs.c
@@ -222,7 +222,11 @@ static const char **get_sorted_attrs(TAL
 		attrs[i] = a;
 	}
 
+#ifdef __COMPAR_FN_T
 	qsort(attrs, n_attrs, sizeof(char *), (__compar_fn_t)strcasecmp_ptr);
+#else
+	qsort(attrs, n_attrs, sizeof(char *), strcasecmp_ptr);
+#endif
 	return attrs;
 }
 
@@ -312,8 +316,13 @@ static int count_attrs_search_callback(s
 				found_attrs[i] = msg->elements[i].name;
 			}
 
+#ifdef __COMPAR_FN_T
 			qsort(found_attrs, msg->num_elements, sizeof(char *),
 			      (__compar_fn_t)strcasecmp_ptr);
+#else
+			qsort(found_attrs, msg->num_elements, sizeof(char *),
+			      strcasecmp_ptr);
+#endif
 
 
 			/* find and report duplicates */
