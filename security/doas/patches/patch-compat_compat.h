$NetBSD: patch-compat_compat.h,v 1.1 2020/10/21 17:34:09 kim Exp $

Do not provide a prototype for reallocarray(3) on NetBSD.

--- compat/compat.h
+++ compat/compat.h
@@ -13,7 +13,9 @@ extern const char *__progname;
 
 const char *getprogname(void);
 
+#if !defined(__NetBSD__)
 void *reallocarray(void *optr, size_t nmemb, size_t size);
+#endif
 
 void setprogname(const char *progname);
 
