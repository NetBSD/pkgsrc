$NetBSD: patch-gcc_config_rs6000_rs6000.cc,v 1.1 2026/04/04 01:29:42 js Exp $

Also use baserel for const - after all, something in a const might refer to
something that gets relocated, so needs to be accessed baserel as well.

--- gcc/config/rs6000/rs6000.cc.orig	2026-04-04 01:09:46.269295661 +0000
+++ gcc/config/rs6000/rs6000.cc
@@ -20973,7 +20973,6 @@ rs6000_elf_encode_section_info (tree dec
       rtx symbol = XEXP (rtl, 0);
 
       if(TREE_CODE (decl) == VAR_DECL &&
-			!TREE_READONLY(decl) &&
 			GET_CODE (symbol) == SYMBOL_REF)
         {
           const char *name = DECL_SECTION_NAME (decl);
