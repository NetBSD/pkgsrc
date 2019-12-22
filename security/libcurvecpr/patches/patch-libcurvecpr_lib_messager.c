$NetBSD: patch-libcurvecpr_lib_messager.c,v 1.1 2019/12/22 22:28:54 joerg Exp $

--- libcurvecpr/lib/messager.c.orig	2019-12-22 17:53:53.626250749 +0000
+++ libcurvecpr/lib/messager.c
@@ -10,10 +10,6 @@
 #include <stdint.h>
 #include <string.h>
 
-#include <sodium/crypto_uint16.h>
-#include <sodium/crypto_uint32.h>
-#include <sodium/crypto_uint64.h>
-
 #define _STOP_SUCCESS 2048
 #define _STOP_FAILURE 4096
 
