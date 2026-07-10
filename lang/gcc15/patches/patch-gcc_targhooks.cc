$NetBSD: patch-gcc_targhooks.cc,v 1.1 2026/07/10 21:28:41 tsutsui Exp $

- Pull NetBSD local change for gcc's default_hidden_stack_protect_fail()
  for NetBSD/i386
   https://cvsweb.netbsd.org/bsdweb.cgi/src/external/gpl3/gcc/dist/gcc/targhooks.cc.diff?r1=1.1.1.2;r2=1.4

--- gcc/targhooks.cc.orig	2026-07-10 18:51:24.043844508 +0000
+++ gcc/targhooks.cc
@@ -1000,7 +1000,17 @@ default_hidden_stack_protect_fail (void)
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
