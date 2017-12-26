$NetBSD: patch-src_plugin.c,v 1.1 2017/12/26 11:27:39 he Exp $

Don't confuse the C preprocessor by supplying what looks
like a single argument into two arguments.  (Confuses SSP macros.)

--- src/plugin.c.orig	2004-11-12 02:52:16.000000000 +0000
+++ src/plugin.c
@@ -123,16 +123,18 @@ static void *dummy_voidptr_null (/*< voi
  * This is just terrible.  Please make me fix this.
  */
 #define APPENDMSG msg + msgwr, sizeof (msg) - msgwr - 1
+#define MSGPTR msg + msgwr
+#define REMAIN sizeof(msg) - msgwr - 1
 #define LOGMSG(fmt,pfx1,pfx2)                                              \
 	char    msg[4096];                                                     \
 	size_t  msgwr = 0;                                                     \
 	va_list args;                                                          \
 	if (pfx1)                                                              \
-		msgwr += snprintf (APPENDMSG, "%s: ", STRING_NOTNULL(pfx1));       \
+		msgwr += snprintf (MSGPTR, REMAIN, "%s: ", STRING_NOTNULL(pfx1));       \
 	if (pfx2)                                                              \
-		msgwr += snprintf (APPENDMSG, "[%s]: ", STRING_NOTNULL(pfx2));     \
+		msgwr += snprintf (MSGPTR, REMAIN, "[%s]: ", STRING_NOTNULL(pfx2));     \
 	va_start (args, fmt);                                                  \
-	vsnprintf (APPENDMSG, fmt, args);                                      \
+	vsnprintf (MSGPTR, REMAIN, fmt, args);                                 \
 	va_end (args);
 
 static int wrapper_dbg (Protocol *p, char *fmt, ...)
