$NetBSD: patch-mozilla_xpcom_typelib_xpt_xpt__arena.h,v 1.1 2020/03/30 19:46:01 joerg Exp $

--- mozilla/xpcom/typelib/xpt/xpt_arena.h.orig	2018-07-09 19:54:58.000000000 +0000
+++ mozilla/xpcom/typelib/xpt/xpt_arena.h
@@ -10,7 +10,7 @@
 #ifndef __xpt_arena_h__
 #define __xpt_arena_h__
 
-#include <stdlib.h>
+#include <cstdlib>
 #include "mozilla/Attributes.h"
 #include "mozilla/MemoryReporting.h"
 #include <stdint.h>
