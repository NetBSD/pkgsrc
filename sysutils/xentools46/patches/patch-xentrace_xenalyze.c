$NetBSD: patch-xentrace_xenalyze.c,v 1.2.2.2 2018/07/05 08:45:27 bsiegert Exp $

Remove unused function, guard misleading indentation (also upstream)

--- xentrace/xenalyze.c.orig	2017-07-06 07:04:28.000000000 +0000
+++ xentrace/xenalyze.c
@@ -2132,10 +2132,12 @@ float weighted_percentile(float * A, /* 
         } while (I <= J); /* Keep going until our pointers meet or pass */
 
         /* Re-adjust L and R, based on which element we're looking for */
-        if(J_weight<K_weight)
+        if(J_weight<K_weight) {
             L=I; L_weight = I_weight;
-        if(K_weight<I_weight)
+	}
+        if(K_weight<I_weight) {
             R=J; R_weight = J_weight;
+	}
     }
 
     return A[L];
@@ -2211,10 +2213,12 @@ long long self_weighted_percentile(long 
         } while (I <= J); /* Keep going until our pointers meet or pass */
 
         /* Re-adjust L and R, based on which element we're looking for */
-        if(J_weight<K_weight)
+        if(J_weight<K_weight) {
             L=I; L_weight = I_weight;
-        if(K_weight<I_weight)
+	}
+        if(K_weight<I_weight) {
             R=J; R_weight = J_weight;
+	}
     }
 
     return A[L];
@@ -4121,6 +4125,7 @@ void cr3_dump_list(struct cr3_value_stru
     struct cr3_value_struct **qsort_array;
     int i, N=0;
 
+#ifdef unusedfunction
     int cr3_compare_total(const void *_a, const void *_b) {
         struct cr3_value_struct *a=*(typeof(&a))_a;
         struct cr3_value_struct *b=*(typeof(&a))_b;
@@ -4137,6 +4142,7 @@ void cr3_dump_list(struct cr3_value_stru
         } else
             return -1;
     }
+#endif
 
     int cr3_compare_start(const void *_a, const void *_b) {
         struct cr3_value_struct *a=*(typeof(&a))_a;
