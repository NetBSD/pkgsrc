$NetBSD: patch-gcc_cp_lex.cc,v 1.1 2026/07/19 11:17:43 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/cp/lex.cc.orig	2026-06-12 06:09:06.352521825 +0000
+++ gcc/cp/lex.cc
@@ -266,6 +266,9 @@ init_reswords (void)
     {
       if (c_common_reswords[i].disable & D_CONLY)
 	continue;
+      if (!flag_allow_extra_keywords
+	  && c_common_reswords[i].disable & D_EXT_C_IN_CXX)
+	continue;
       id = get_identifier (c_common_reswords[i].word);
       C_SET_RID_CODE (id, c_common_reswords[i].rid);
       ridpointers [(int) c_common_reswords[i].rid] = id;
