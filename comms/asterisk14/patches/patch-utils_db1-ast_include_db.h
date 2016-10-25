$NetBSD: patch-utils_db1-ast_include_db.h,v 1.1.1.1 2016/10/25 08:17:07 jnemeth Exp $

--- utils/db1-ast/include/db.h.orig	2015-10-09 21:48:48.000000000 +0000
+++ utils/db1-ast/include/db.h
@@ -55,7 +55,7 @@
 
 #ifndef	__BIT_TYPES_DEFINED__
 #define	__BIT_TYPES_DEFINED__
-#if (!defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__APPLE__))
+#if (!defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__APPLE__) && !defined(__DragonFly__))
 typedef	__signed char		   int8_t;
 typedef	short			  int16_t;
 typedef	int			  int32_t;
