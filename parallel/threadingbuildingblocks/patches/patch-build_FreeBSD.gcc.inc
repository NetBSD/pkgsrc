$NetBSD: patch-build_FreeBSD.gcc.inc,v 1.1 2013/10/20 17:58:06 joerg Exp $

--- build/FreeBSD.gcc.inc.orig	2013-10-18 13:29:39.000000000 +0000
+++ build/FreeBSD.gcc.inc
@@ -88,7 +88,7 @@ endif 
 # Setting tbbmalloc data.
 #------------------------------------------------------------------------------
 
-M_CPLUS_FLAGS = $(CPLUS_FLAGS) -fno-rtti -fno-exceptions -fno-schedule-insns2
+M_CPLUS_FLAGS = $(CPLUS_FLAGS) -fno-rtti -fno-exceptions
 
 #------------------------------------------------------------------------------
 # End of setting tbbmalloc data.
