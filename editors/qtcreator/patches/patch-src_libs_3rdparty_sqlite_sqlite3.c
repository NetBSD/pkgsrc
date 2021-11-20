$NetBSD: patch-src_libs_3rdparty_sqlite_sqlite3.c,v 1.1 2021/11/20 20:51:14 wiz Exp $

By default, the code tries to use localtime_s and fails.

--- src/libs/3rdparty/sqlite/sqlite3.c.orig	2021-11-03 11:13:14.000000000 +0000
+++ src/libs/3rdparty/sqlite/sqlite3.c
@@ -22478,6 +22478,10 @@ static void clearYMD_HMS_TZ(DateTime *p)
 ** already, check for an MSVC build environment that provides
 ** localtime_s().
 */
+#ifdef __NetBSD__
+#undef HAVE_LOCALTIME_R
+#define HAVE_LOCALTIME_R	1
+#endif
 #if !HAVE_LOCALTIME_R && !HAVE_LOCALTIME_S \
     && defined(_MSC_VER) && defined(_CRT_INSECURE_DEPRECATE)
 #undef  HAVE_LOCALTIME_S
