$NetBSD: patch-gcc_targhooks.c,v 1.1.2.2 2017/10/15 13:59:45 spz Exp $

* Port from NetBSD src
  Fix __stack_chk_fail_local undefined reference error
  from "gcc test.c -fstack-protector-all -fPIE".

--- gcc/targhooks.c.orig	2014-03-03 21:51:58.000000000 +0000
+++ gcc/targhooks.c
@@ -738,7 +738,17 @@ default_hidden_stack_protect_fail (void)
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
