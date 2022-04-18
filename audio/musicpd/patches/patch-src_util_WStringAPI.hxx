$NetBSD: patch-src_util_WStringAPI.hxx,v 1.1 2022/04/18 18:13:55 nia Exp $

std::wcpcpy is undefined on illumos, whereas wcpcpy isn't,
so the __sun specifics are actively harmful.

--- src/util/WStringAPI.hxx.orig	2022-03-14 17:55:47.000000000 +0000
+++ src/util/WStringAPI.hxx
@@ -125,8 +125,6 @@ UnsafeCopyStringP(wchar_t *dest, const w
 	/* emulate wcpcpy() */
 	UnsafeCopyString(dest, src);
 	return dest + StringLength(dest);
-#elif defined(__sun) && defined (__SVR4)
-	return std::wcpcpy(dest, src);
 #else
 	return wcpcpy(dest, src);
 #endif
@@ -203,11 +201,7 @@ StringCollate(const wchar_t *a, const wc
 static inline wchar_t *
 DuplicateString(const wchar_t *p) noexcept
 {
-#if defined(__sun) && defined (__SVR4)
-	return std::wcsdup(p);
-#else
 	return wcsdup(p);
-#endif
 }
 
 #endif
