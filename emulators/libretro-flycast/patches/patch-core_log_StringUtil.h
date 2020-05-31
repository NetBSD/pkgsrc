$NetBSD: patch-core_log_StringUtil.h,v 1.1 2020/05/31 15:20:22 nia Exp $

Make this compile on NetBSD...

--- core/log/StringUtil.h.orig	2020-05-29 12:45:55.000000000 +0000
+++ core/log/StringUtil.h
@@ -24,7 +24,7 @@ int vasprintf(char **s, const char *fmt,
 }
 #endif
 
-#if !defined(_WIN32) && !defined(ANDROID) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(HAVE_LIBNX)
+#if !defined(_WIN32) && !defined(ANDROID) && !defined(__HAIKU__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(HAVE_LIBNX)
 static locale_t GetCLocale()
 {
   static locale_t c_locale = newlocale(LC_ALL_MASK, "C", nullptr);
@@ -69,11 +69,11 @@ bool CharArrayFromFormatV(char* out, int
   writtenCount = vsnprintf(out, outsize, format, args);
 #endif
 #else
-#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(HAVE_LIBNX)
+#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(HAVE_LIBNX)
   locale_t previousLocale = uselocale(GetCLocale());
 #endif
   writtenCount = vsnprintf(out, outsize, format, args);
-#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(HAVE_LIBNX)
+#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(HAVE_LIBNX)
   uselocale(previousLocale);
 #endif
 #endif
@@ -101,7 +101,7 @@ std::string StringFromFormatV(const char
   std::string temp = buf;
   delete[] buf;
 #else
-#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(HAVE_LIBNX)
+#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(HAVE_LIBNX)
   locale_t previousLocale = uselocale(GetCLocale());
 #endif
   if (vasprintf(&buf, format, args) < 0)
@@ -110,7 +110,7 @@ std::string StringFromFormatV(const char
     buf = nullptr;
   }
 
-#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(HAVE_LIBNX)
+#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(HAVE_LIBNX)
   uselocale(previousLocale);
 #endif
 
