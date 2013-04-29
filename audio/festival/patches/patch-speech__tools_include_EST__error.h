$NetBSD: patch-speech__tools_include_EST__error.h,v 1.1 2013/04/29 21:12:37 joerg Exp $

--- speech_tools/include/EST_error.h.orig	2013-04-28 06:54:36.000000000 +0000
+++ speech_tools/include/EST_error.h
@@ -84,19 +84,19 @@ void EST_quiet_error_fn(const char *form
 void EST_quiet_sys_error_fn(const char *format, ...);
 
 
-#define __S_(X) #X
-#define __s_(X) __S_(X)
+#define STR_(X) #X
+#define str_(X) STR_(X)
 
-#define EST_bug       (EST_error_where = __FILE__ ", line " __s_(__LINE__)),\
+#define EST_bug       (EST_error_where = __FILE__ ", line " str_(__LINE__)),\
 			(*EST_bug_func)
 
 #if defined(EST_DEBUGGING)
 #define EST_exit(N) abort()
-#define EST_error     (EST_error_where = __FILE__ ", line " __s_(__LINE__)),\
+#define EST_error     (EST_error_where = __FILE__ ", line " str_(__LINE__)),\
 			(*EST_error_func)
-#define EST_warning   (EST_error_where = __FILE__ ", line " __s_(__LINE__)),\
+#define EST_warning   (EST_error_where = __FILE__ ", line " str_(__LINE__)),\
 			(*EST_warning_func)
-#define EST_sys_error (EST_error_where = __FILE__ ", line " __s_(__LINE__)),\
+#define EST_sys_error (EST_error_where = __FILE__ ", line " str_(__LINE__)),\
 			  (*EST_sys_error_func)
 #else
 
