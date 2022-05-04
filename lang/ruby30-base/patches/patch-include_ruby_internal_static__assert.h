$NetBSD: patch-include_ruby_internal_static__assert.h,v 1.1 2022/05/04 16:44:53 taca Exp $

Add the way to stop using static_assert.

--- include/ruby/internal/static_assert.h.orig	2022-04-12 11:48:55.000000000 +0000
+++ include/ruby/internal/static_assert.h
@@ -50,7 +50,7 @@
 #elif defined(__STDC_VERSION__) && RBIMPL_COMPILER_SINCE(GCC, 4, 6, 0)
 # define RBIMPL_STATIC_ASSERT0 __extension__ _Static_assert
 
-#elif defined(static_assert)
+#elif defined(static_assert) && !defined(RB_AVOID_STATIC_ASSERT)
 # /* Take <assert.h> definition */
 # define RBIMPL_STATIC_ASSERT0 static_assert
 #endif
