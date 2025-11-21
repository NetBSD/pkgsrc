$NetBSD: patch-lib_crau_crau.h,v 1.1 2025/11/21 16:44:57 manu Exp $

Build fix with gcc. The configure test may be wrong

--- lib/crau/crau.h.orig	2025-10-24 08:10:22.000000000 +0200
+++ lib/crau/crau.h	2025-11-21 10:19:16.044976391 +0100
@@ -250,13 +250,13 @@
 
 # else
 
 #  ifndef CRAU_MAYBE_UNUSED
-#   if defined(__has_c_attribute) && \
+#   if defined(__GNUC__)
+#    define CRAU_MAYBE_UNUSED __attribute__((__unused__))
+#   elif defined(__has_c_attribute) && \
     __has_c_attribute (__maybe_unused__)
 #    define CRAU_MAYBE_UNUSED [[__maybe_unused__]]
-#   elif defined(__GNUC__)
-#    define CRAU_MAYBE_UNUSED __attribute__((__unused__))
 #   endif
 #  endif /* CRAU_MAYBE_UNUSED */
 
 void crau_push_context(struct crau_context_stack_st *stack CRAU_MAYBE_UNUSED,
