$NetBSD: patch-mysys_my__largepage.c,v 1.1 2021/05/23 15:32:47 nia Exp $

NetBSD does not have MAP_ALIGNED_SUPER.

--- mysys/my_largepage.c.orig	2021-05-05 21:00:19.000000000 +0000
+++ mysys/my_largepage.c
@@ -336,8 +336,12 @@ uchar *my_large_malloc(size_t *size, myf
 # warning "No explicit large page (HUGETLB pages) support in Linux < 3.8"
 #endif
 #elif defined(MAP_ALIGNED)
+#ifdef MAP_ALIGNED_SUPER
         mapflag|= MAP_ALIGNED_SUPER |
                   MAP_ALIGNED(my_bit_log2_size_t(large_page_size));
+#else
+        mapflag|= MAP_ALIGNED(my_bit_log2_size_t(large_page_size));
+#endif
 #endif
         aligned_size= MY_ALIGN(*size, (size_t) large_page_size);
       }
