$NetBSD: patch-cmake_FindEnchant.cmake,v 1.1 2018/11/27 13:07:26 bsiegert Exp $

--- cmake/FindEnchant.cmake.orig	2017-12-22 18:02:24.000000000 +0000
+++ cmake/FindEnchant.cmake
@@ -24,7 +24,7 @@ find_path(ENCHANT_INCLUDE_DIR
   PATH_SUFFIXES "enchant")
 
 find_library(ENCHANT_LIBRARIES
-  NAMES enchant
+  NAMES enchant-2
   HINTS ${PC_ENCHANT_LIBRARY_DIRS})
 
 if(ENCHANT_INCLUDE_DIR AND ENCHANT_LIBRARIES)
@@ -39,7 +39,7 @@ if(ENCHANT_INCLUDE_DIR AND ENCHANT_LIBRA
   #include <stdlib.h>
   #include <stddef.h>
   #include <string.h>
-  #include <enchant/enchant.h>
+  #include <enchant.h>
 
   EnchantBroker *enchant_broker_init();
   char **enchant_dict_suggest(EnchantDict *dict, const char *str,
