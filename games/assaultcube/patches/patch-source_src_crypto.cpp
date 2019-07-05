$NetBSD: patch-source_src_crypto.cpp,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/crypto.cpp.orig	2013-10-09 08:27:37.000000000 +0000
+++ source/src/crypto.cpp
@@ -763,7 +763,7 @@ bool hashstring(const char *str, char *r
 const char *genpwdhash(const char *name, const char *pwd, int salt)
 {
     static string temp;
-    formatstring(temp)("%s %d %s %s %d", pwd, salt, name, pwd, abs(PROTOCOL_VERSION));
+    formatstring(temp)("%s %d %s %s %d", pwd, salt, name, pwd, iabs(PROTOCOL_VERSION));
     tiger::hashval hash;
     tiger::hash((uchar *)temp, (int)strlen(temp), hash);
     formatstring(temp)("%llx %llx %llx", hash.chunks[0], hash.chunks[1], hash.chunks[2]);
