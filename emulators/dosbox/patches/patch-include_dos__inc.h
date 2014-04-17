$NetBSD: patch-include_dos__inc.h,v 1.1 2014/04/17 00:49:51 wiz Exp $

Add missing header for offsetof() and friends.

--- include/dos_inc.h.orig	2010-05-10 17:43:54.000000000 +0000
+++ include/dos_inc.h
@@ -27,6 +27,7 @@
 #ifndef DOSBOX_MEM_H
 #include "mem.h"
 #endif
+#include <stddef.h>
 
 #ifdef _MSC_VER
 #pragma pack (1)
