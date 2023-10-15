$NetBSD: patch-src_libutil_strutil.cpp,v 1.1 2023/10/15 19:52:09 ryoon Exp $

* For NetBSD

--- src/libutil/strutil.cpp.orig	2023-06-01 17:26:37.000000000 +0000
+++ src/libutil/strutil.cpp
@@ -63,7 +63,7 @@ static std::mutex output_mutex;
 // On systems that support it, get a location independent locale.
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) \
     || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)           \
-    || defined(__GLIBC__)
+    || defined(__GLIBC__) || defined(__NetBSD__)
 static locale_t c_loc = newlocale(LC_ALL_MASK, "C", nullptr);
 #elif defined(_WIN32)
 static _locale_t c_loc = _create_locale(LC_ALL, "C");
@@ -452,6 +452,14 @@ strcasecmp(const char* a, const char* b)
     return strcasecmp_l(a, b, c_loc);
 #elif defined(_WIN32)
     return _stricmp_l(a, b, c_loc);
+#elif defined(__NetBSD__)
+    const unsigned char *us1 = (const unsigned char *)a,
+                    *us2 = (const unsigned char *)b;
+
+    while (tolower_l(*us1, c_loc) == tolower_l(*us2++, c_loc))
+            if (*us1++ == '\0')
+                    return (0);
+    return (tolower_l(*us1, c_loc) - tolower_l(*--us2, c_loc));
 #else
 #    error("need equivalent of strcasecmp_l on this platform");
 #endif
@@ -467,6 +475,19 @@ strncasecmp(const char* a, const char* b
     return strncasecmp_l(a, b, size, c_loc);
 #elif defined(_WIN32)
     return _strnicmp_l(a, b, size, c_loc);
+#elif defined(__NetBSD__)
+    if (size != 0) {
+            const unsigned char *us1 = (const unsigned char *)a,
+                            *us2 = (const unsigned char *)b;
+
+            do {
+                    if (tolower_l(*us1, c_loc) != tolower_l(*us2++, c_loc))
+                            return (tolower_l(*us1, c_loc) - tolower_l(*--us2, c_loc));
+                    if (*us1++ == '\0')
+                            break;
+            } while (--size != 0);
+    }
+    return (0);
 #else
 #    error("need equivalent of strncasecmp_l on this platform");
 #endif
