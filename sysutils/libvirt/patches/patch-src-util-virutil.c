$NetBSD: patch-src-util-virutil.c,v 1.1 2014/01/25 02:54:27 agc Exp $

Only use uselocale() if we have it

--- src/util/virutil.c	2014/01/25 02:40:22	1.1
+++ src/util/virutil.c	2014/01/25 02:41:41
@@ -428,9 +428,13 @@
     if (virLocaleInitialize() < 0)
         goto error;
 
+#ifdef HAVE_USELOCALE
     old_loc = uselocale(virLocale);
+#endif
     ret = virAsprintf(strp, "%lf", number);
+#ifdef HAVE_USELOCALE
     uselocale(old_loc);
+#endif
 
 #else
 
