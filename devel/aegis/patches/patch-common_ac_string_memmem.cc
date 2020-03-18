$NetBSD: patch-common_ac_string_memmem.cc,v 1.1 2020/03/18 17:46:18 joerg Exp $

--- common/ac/string/memmem.cc.orig	2020-03-18 14:02:19.961788638 +0000
+++ common/ac/string/memmem.cc
@@ -182,7 +182,7 @@ memmem_replacement(const void *haystack_
 
     // Use optimizations in memchr when possible.
     if (needle_len == 1)
-        return memchr(haystack, *needle, haystack_len);
+        return const_cast<void *>(memchr(haystack, *needle, haystack_len));
 
     // Minimizing the worst-case complexity:
     // Let n = haystack_len, m = needle_len.
