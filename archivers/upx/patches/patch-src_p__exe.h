$NetBSD: patch-src_p__exe.h,v 1.3 2014/05/26 01:30:39 rodent Exp $

--- src/p_exe.h.orig	2013-09-30 15:51:00.000000000 +0000
+++ src/p_exe.h
@@ -105,7 +105,7 @@ protected:
     enum {
         NORELOC = 1,
         USEJUMP = 2,
-        SS = 4,
+        upx_SS = 4,
         SP = 8,
         MINMEM = 16,
         MAXMEM = 32
