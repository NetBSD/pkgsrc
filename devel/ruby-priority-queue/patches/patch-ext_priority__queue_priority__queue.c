$NetBSD: patch-ext_priority__queue_priority__queue.c,v 1.2 2023/09/09 13:47:11 taca Exp $

Do not declar/define bool, false, true if already defined.

--- ext/priority_queue/priority_queue.c.orig	2023-09-09 13:39:21.027954251 +0000
+++ ext/priority_queue/priority_queue.c
@@ -24,10 +24,16 @@
 #include "ruby.h"
 #include <math.h>
 
+#ifndef bool
 typedef _Bool bool;
+#endif
 
+#ifndef false
 #define false 0;
+#endif
+#ifndef true
 #define true 1;
+#endif
 
 // Node Structure
 typedef struct struct_priority_node {
@@ -285,7 +291,7 @@ priority_node* priority_queue_delete_min
 	n = n->right;
       } while (n!=min->child);
 
-      // Kinder einfügen
+      // Kinder einfÃ¼gen
       if (q->rootlist) {
 	priority_node* const l1 = q->rootlist->left;
 	priority_node* const l2 = n->left;
@@ -299,10 +305,10 @@ priority_node* priority_queue_delete_min
       }
     }
 
-    // Größe anpassen
+    // GrÃ¶ÃŸe anpassen
     q->length = length-1;
 
-    // Wieder aufhübschen
+    // Wieder aufhÃ¼bschen
     consolidate_queue(q);
   }
 
@@ -817,7 +823,7 @@ void pq_node2dot(VALUE result_string, pr
       pq_node2dot(result_string, n1, level + 1);
       for (i=0; i<level; i++) rb_str_cat2(result_string, "  ");  
       rb_str_concat(result_string,
-	  rb_funcall(Qnil, id_format, 4, rb_str_new2("NODE%i -> NODE%i;\n"), 
+	  rb_funcall(Qnil, id_format, 3, rb_str_new2("NODE%i -> NODE%i;\n"), 
 	    ULONG2NUM((unsigned long) n), ULONG2NUM((unsigned long) n1)));
       n1 = n1->right;
     } while(n1 != n->child);
@@ -874,7 +880,7 @@ VALUE pq_each(VALUE self) {
 }
 
 static
-VALUE pq_insert_node(VALUE node, VALUE queue) {
+VALUE pq_insert_node(VALUE node, VALUE queue, int _argc, const VALUE *_argv, VALUE _blockarg) {
   return pq_push(queue, rb_ary_entry(node, 0), rb_ary_entry(node, 1));
 }
 
@@ -883,7 +889,7 @@ VALUE pq_initialize_copy(VALUE copy, VAL
   if (copy == orig)
     return copy;
 
-  rb_iterate(rb_each, orig, pq_insert_node, copy);
+  rb_block_call(orig, rb_intern("each"), 0, NULL, pq_insert_node, copy);
   
   return copy;
 }
