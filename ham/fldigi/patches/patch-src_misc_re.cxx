$NetBSD: patch-src_misc_re.cxx,v 1.1 2013/05/06 14:49:32 joerg Exp $

--- src/misc/re.cxx.orig	2013-05-03 14:24:52.000000000 +0000
+++ src/misc/re.cxx
@@ -120,12 +120,17 @@ void re_t::suboff(size_t n, int* start, 
 	}
 }
 
+#if __cplusplus >= 201103L
+#include <functional>
+#else
 #include <tr1/functional>
+using tr1::hash;
+#endif
 
 size_t re_t::hash(void) const
 {
-	size_t h = tr1::hash<string>()(pattern);
-	return h ^ (tr1::hash<int>()(cflags) + 0x9e3779b9 + (h << 6) + (h >> 2));
+	size_t h = ::hash<string>()(pattern);
+	return h ^ (::hash<int>()(cflags) + 0x9e3779b9 + (h << 6) + (h >> 2));
 }
 
 // ------------------------------------------------------------------------
