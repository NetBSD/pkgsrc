$NetBSD: patch-include_nasmlib.h,v 1.1 2018/05/20 16:36:04 jakllsch Exp $

error: 'pure' attribute on function returning 'void'

--- include/nasmlib.h.orig	2018-02-07 21:40:15.000000000 +0000
+++ include/nasmlib.h
@@ -191,7 +191,7 @@ int64_t readstrnum(char *str, int length
  * seg_init: Initialise the segment-number allocator.
  * seg_alloc: allocate a hitherto unused segment number.
  */
-void pure_func seg_init(void);
+void seg_init(void);
 int32_t pure_func seg_alloc(void);
 
 /*
