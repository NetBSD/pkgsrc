$NetBSD: patch-gcc_targhooks.cc,v 1.1 2024/05/15 12:22:18 ryoon Exp $

* Patch from NetBSD src. Fix -fPIC/-fPIE and -fstack-protector-strong/
  -fstack-protector-all causes undefined reference to `__stack_chk_fail_local'
  under NetBSD/i386 9 at least.

--- gcc/targhooks.cc.orig	2024-05-14 16:02:43.062711061 +0000
+++ gcc/targhooks.cc
@@ -961,7 +961,17 @@ default_hidden_stack_protect_fail (void)
       DECL_ARTIFICIAL (t) = 1;
       DECL_IGNORED_P (t) = 1;
       DECL_VISIBILITY_SPECIFIED (t) = 1;
+#if defined(__NetBSD__)
+      /*
+       * This is a hack:
+       * It appears that our gas does not generate @PLT for hidden
+       * symbols. It could be that we need a newer version, or that
+       * this local function is handled differently on linux.
+       */
+      DECL_VISIBILITY (t) = VISIBILITY_DEFAULT;
+#else
       DECL_VISIBILITY (t) = VISIBILITY_HIDDEN;
+#endif
 
       stack_chk_fail_decl = t;
     }
