$NetBSD: patch-caretx.c,v 1.2 2018/10/15 03:01:37 taca Exp $

* NetBSD's implementation sometimes returns "/"; reject that too.
* Apply 03b94aa47e981af3c7b0118bfb11facda2b95251 from upstream make
  $^X fallback work when platform-specific technique fails.

--- caretx.c.orig	2018-05-21 12:29:23.000000000 +0000
+++ caretx.c
@@ -56,7 +56,19 @@ Perl_set_caret_X(pTHX) {
     SV *const caret_x = GvSV(tmpgv);
 #if defined(OS2)
     sv_setpv(caret_x, os2_execname(aTHX));
-#elif defined(USE_KERN_PROC_PATHNAME)
+    return;
+#elif defined(WIN32)
+    char *ansi;
+    WCHAR widename[MAX_PATH];
+    GetModuleFileNameW(NULL, widename, sizeof(widename)/sizeof(WCHAR));
+    ansi = win32_ansipath(widename);
+    sv_setpv(caret_x, ansi);
+    win32_free(ansi);
+    return;
+#else
+    /* We can try a platform-specific one if possible; if it fails, or we
+     * aren't running on a suitable platform, we'll fall back to argv[0]. */
+# ifdef USE_KERN_PROC_PATHNAME
     size_t size = 0;
     int mib[4];
     mib[0] = CTL_KERN;
@@ -76,7 +88,7 @@ Perl_set_caret_X(pTHX) {
             return;
         }
     }
-#elif defined(USE_NSGETEXECUTABLEPATH)
+# elif defined(USE_NSGETEXECUTABLEPATH)
     char buf[1];
     uint32_t size = sizeof(buf);
 
@@ -95,7 +107,7 @@ Perl_set_caret_X(pTHX) {
             return;
         }
     }
-#elif defined(HAS_PROCSELFEXE)
+# elif defined(HAS_PROCSELFEXE)
     char buf[MAXPATHLEN];
     SSize_t len = readlink(PROCSELFEXE_PATH, buf, sizeof(buf) - 1);
     /* NOTE: if the length returned by readlink() is sizeof(buf) - 1,
@@ -120,20 +132,14 @@ Perl_set_caret_X(pTHX) {
        to the executable (or returning an error from the readlink). Any
        valid path has a '/' in it somewhere, so use that to validate the
        result. See http://www.freebsd.org/cgi/query-pr.cgi?pr=35703
+
+       NetBSD's implementation sometimes returns "/"; reject that too.
     */
-    if (len > 0 && memchr(buf, '/', len)) {
+    if (len > 1 && memchr(buf, '/', len)) {
         sv_setpvn(caret_x, buf, len);
         return;
     }
-#elif defined(WIN32)
-    char *ansi;
-    WCHAR widename[MAX_PATH];
-    GetModuleFileNameW(NULL, widename, sizeof(widename)/sizeof(WCHAR));
-    ansi = win32_ansipath(widename);
-    sv_setpv(caret_x, ansi);
-    win32_free(ansi);
-    return;
-#else
+# endif
     /* Fallback to this:  */
     sv_setpv(caret_x, PL_origargv[0]);
 #endif
