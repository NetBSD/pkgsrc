$NetBSD: patch-lib_misc_codesetOld.c,v 1.1 2025/11/17 17:38:39 adam Exp $

--- lib/misc/codesetOld.c.orig	2025-09-18 01:06:36.000000000 +0000
+++ lib/misc/codesetOld.c
@@ -662,7 +662,7 @@ CodeSetOldGetCodeSetFromLocale(void)
    codeset = Util_SafeStrdup(nl_langinfo_l(CODESET, new));
    freelocale(new);
 
-#elif defined(sun)
+#elif defined(sun) || defined(__NetBSD__)
 
    char *locale = setlocale(LC_CTYPE, NULL);
 
@@ -928,7 +928,7 @@ CodeSetOld_GenericToGenericDb(char const
        * change bufIn so a simple cast is safe. --plangdale
        */
 
-#if defined(__linux__) || defined(__EMSCRIPTEN__)
+#if defined(__linux__) || defined(__EMSCRIPTEN__) || defined(__NetBSD__)
       status = iconv(cd, (char **)&bufIn, &sizeIn, &out, &outLeft);
 #else
       status = iconv(cd, &bufIn, &sizeIn, &out, &outLeft);
