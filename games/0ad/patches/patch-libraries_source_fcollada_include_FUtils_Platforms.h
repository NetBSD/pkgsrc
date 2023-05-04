$NetBSD: patch-libraries_source_fcollada_include_FUtils_Platforms.h,v 1.1 2023/05/04 15:20:52 nikita Exp $

--- libraries/source/fcollada/include/FUtils/Platforms.h.orig	2012-06-04 21:33:15.000000000 +0000
+++ libraries/source/fcollada/include/FUtils/Platforms.h
@@ -74,7 +74,7 @@
 #include <wchar.h>
 #include <stdint.h>
 
-#elif defined(LINUX) || defined(__PPU__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#elif defined(LINUX) || defined(__PPU__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <ctype.h>
 #include <wctype.h>
 #include <unistd.h>
@@ -82,9 +82,9 @@
 #include <wchar.h>
 #include <stdarg.h>
 
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 #include <malloc.h>
-#endif // !__FreeBSD__ && !__OpenBSD__
+#endif // !__FreeBSD__ && !__NetBSD__ && !__OpenBSD__
 
 #include <stdlib.h>
 #include <stdio.h>
@@ -125,7 +125,7 @@ typedef uint8_t byte;
 #endif // PLATFORMS
 
 // Important functions that some OSes have missing!
-#if defined(__APPLE__) || defined(LINUX) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(LINUX) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
 inline char* strlower(char* str) { char* it = str; while (*it != 0) { *it = tolower(*it); ++it; } return str; }
 inline wchar_t* wcslwr(wchar_t* str) { wchar_t* it = str; while (*it != 0) { *it = towlower(*it); ++it; } return str; }
 inline int wcsicmp(const wchar_t* s1, const wchar_t* s2) { wchar_t c1 = *s1, c2 = *s2; while (c1 != 0 && c2 != 0) { if (c1 >= 'a' && c1 <= 'z') c1 -= 'a' + 'A'; if (c2 >= 'a' && c2 <= 'z') c2 -= 'a' + 'A'; if (c2 < c1) return -1; else if (c2 > c1) return 1; c1 = *(++s1); c2 = *(++s2); } return 0; }
@@ -139,7 +139,7 @@ inline int wcsicmp(const wchar_t* s1, co
 #elif defined(__PPU__)
 #define glClearDepth glClearDepthf
 
-#endif // __APPLE__ || LINUX || _FreeBSD__ || __FreeBSD_kernel__ || __OpenBSD__
+#endif // __APPLE__ || LINUX || _FreeBSD__ || __FreeBSD_kernel__ || __NetBSD__ || __OpenBSD__
 
 // Cross-platform needed functions
 #ifdef WIN32
