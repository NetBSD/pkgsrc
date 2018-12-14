$NetBSD: patch-src_commonstuff.h,v 1.1 2018/12/14 07:19:39 schmonz Exp $

Add DEBUGTUPLE and VERBOSETUPLE macros.

--- src/commonstuff.h.orig	2011-06-18 19:58:29.000000000 +0000
+++ src/commonstuff.h
@@ -28,6 +28,20 @@
 
 extern char *progname, *debug, *verbose;
 
+#define DEBUGTUPLE(m1,m2,m3,m4)	\
+    if (debug) { \
+	write_error_string(progname); \
+	write_error_string(": "); \
+	write_error_string(m1); \
+	write_error_string(" ("); \
+	write_error_string(m2); \
+	write_error_string(","); \
+	write_error_string(m3); \
+	write_error_string(","); \
+	write_error_string(m4); \
+	write_error_string(")\n"); \
+    }
+
 #define DEBUG4(m1,m2,m3,m4)	\
     if (debug) { \
 	write_error_string(progname); \
@@ -43,6 +57,20 @@ extern char *progname, *debug, *verbose;
 #define DEBUG2(m1,m2)		DEBUG4(m1,m2,NULL,NULL)
 #define DEBUG3(m1,m2,m3)	DEBUG4(m1,m2,m3,NULL)
 
+#define VERBOSETUPLE(m1,m2,m3,m4)	\
+    if (verbose) { \
+	write_error_string(progname); \
+	write_error_string(": "); \
+	write_error_string(m1); \
+	write_error_string(" ("); \
+	write_error_string(m2); \
+	write_error_string(","); \
+	write_error_string(m3); \
+	write_error_string(","); \
+	write_error_string(m4); \
+	write_error_string(")\n"); \
+    }
+
 #define VERBOSE4(m1,m2,m3,m4)	\
     if (verbose) { \
 	write_error_string(progname); \
