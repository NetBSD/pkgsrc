$NetBSD: patch-core_log_StringUtil.h,v 1.1 2023/07/02 17:32:30 nia Exp $

Fix build on NetBSD.

--- core/log/StringUtil.h.orig	2023-02-15 17:59:44.000000000 +0000
+++ core/log/StringUtil.h
@@ -69,11 +69,11 @@ bool CharArrayFromFormatV(char* out, int
   writtenCount = vsnprintf(out, outsize, format, args);
 #endif
 #else
-#if !defined(__ANDROID__) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(__SWITCH__)
+#if !defined(__ANDROID__) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(__SWITCH__) && !defined(__NetBSD__)
   locale_t previousLocale = uselocale(GetCLocale());
 #endif
   writtenCount = vsnprintf(out, outsize, format, args);
-#if !defined(__ANDROID__) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(__SWITCH__)
+#if !defined(__ANDROID__) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(__SWITCH__) && !defined(__NetBSD__)
   uselocale(previousLocale);
 #endif
 #endif
@@ -101,7 +101,7 @@ std::string StringFromFormatV(const char
   std::string temp = buf;
   delete[] buf;
 #else
-#if !defined(__ANDROID__) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(__SWITCH__)
+#if !defined(__ANDROID__) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(__SWITCH__) && !defined(__NetBSD__)
   locale_t previousLocale = uselocale(GetCLocale());
 #endif
   if (vasprintf(&buf, format, args) < 0)
@@ -110,7 +110,7 @@ std::string StringFromFormatV(const char
     buf = nullptr;
   }
 
-#if !defined(__ANDROID__) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(__SWITCH__)
+#if !defined(__ANDROID__) && !defined(__HAIKU__) && !defined(__OpenBSD__) && !defined(__SWITCH__) && !defined(__NetBSD__)
   uselocale(previousLocale);
 #endif
 
