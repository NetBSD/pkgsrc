$NetBSD: patch-gcc_targhooks.c,v 1.1.2.2 2023/01/21 14:48:41 bsiegert Exp $

* Port from NetBSD src
  Fix __stack_chk_fail_local undefined reference error
  from "gcc test.c -fstack-protector-all -fPIE".

--- gcc/targhooks.c.orig	2020-03-12 11:07:21.000000000 +0000
+++ gcc/targhooks.c
@@ -949,7 +949,17 @@ default_hidden_stack_protect_fail (void)
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
