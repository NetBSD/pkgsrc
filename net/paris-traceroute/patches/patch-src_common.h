$NetBSD: patch-src_common.h,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/common.h.orig	2020-03-27 18:18:13.457796123 +0000
+++ src/common.h
@@ -41,7 +41,7 @@ const char* lvl2str (int lvl);
 #ifdef __GNUC__
 void log_c (int lvl, const char* file, int line, const char* format, ...)
 		__attribute__ ((format (printf, 4, 5)));
-#define log(lvl, args... ) \
+#define mylog(lvl, args... ) \
 	if (lvl <= get_log_level()) log_c(lvl, __FILE__, __LINE__, ## args )
 
 const char* str_log_c (int lvl, const char* file, int line,
@@ -50,7 +50,7 @@ const char* str_log_c (int lvl, const ch
 
 #else // __GNUC__
 void log_c (int lvl, const char* file, int line, const char* format, ...);
-#define log(lvl, ...) \
+#define mylog(lvl, ...) \
 	if (lvl <= get_log_level()) log_c(lvl, __FILE__, __LINE__, __VA_ARGS__)
 const char* str_log_c (int lvl, const char* file, int line,
 	const char* fortmat, ...);
