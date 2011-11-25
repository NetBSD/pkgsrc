$NetBSD: patch-common_AppGlue.h,v 1.1 2011/11/25 21:42:44 joerg Exp $

--- common/AppGlue.h.orig	2011-11-25 17:56:08.000000000 +0000
+++ common/AppGlue.h
@@ -30,8 +30,8 @@
 class CCvsConsole
 {
 public:
-	virtual long cvs_out(char *txt, long len) = 0L;
-	virtual long cvs_err(char *txt, long len) = 0L;
+	virtual long cvs_out(char *txt, long len) = 0;
+	virtual long cvs_err(char *txt, long len) = 0;
 };
 
 #define errInternal -99
