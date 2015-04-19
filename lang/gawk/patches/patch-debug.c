$NetBSD: patch-debug.c,v 1.1 2015/04/19 14:26:06 tnn Exp $

Avoid conflict with serialize(2) system call on HP-UX.

--- debug.c.orig	2014-03-05 04:31:02.000000000 +0000
+++ debug.c
@@ -200,6 +200,9 @@ static const char *const env_variable[] 
 "DGAWK_HISTORY",
 "DGAWK_OPTION",
 };
+#if defined(__hpux)
+#define serialize gawk_serialize
+#endif
 static void serialize(int );
 static void unserialize(int );
 static const char *commands_string = NULL;
