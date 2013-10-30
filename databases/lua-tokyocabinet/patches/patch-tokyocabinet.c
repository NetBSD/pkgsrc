$NetBSD: patch-tokyocabinet.c,v 1.2 2013/10/30 10:36:12 obache Exp $

* Lua 5.2 API change

--- tokyocabinet.c.orig	2010-09-19 23:14:07.000000000 +0000
+++ tokyocabinet.c
@@ -34,6 +34,13 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#ifdef LUA_VERSION_NUM
+# if (LUA_VERSION_NUM >= 502)
+#undef lua_objlen
+#define lua_objlen lua_rawlen
+# endif
+#endif
+
 #define SWAB16(TC_num) \
   ( \
    ((TC_num & 0x00ffU) << 8) | \
