$NetBSD: patch-extra_sigmund~_sigmund~.c,v 1.3 2012/02/05 21:55:15 sbd Exp $

alloca.h is not portable.
https://sourceforge.net/tracker/?func=detail&aid=3411730&group_id=55736&atid=478072

--- extra/sigmund~/sigmund~.c.orig	2010-07-28 20:55:17.000000000 +0000
+++ extra/sigmund~/sigmund~.c
@@ -26,10 +26,10 @@ for example, defines this in the file d_
 #include <math.h>
 #include <stdio.h>
 #include <string.h>
-#ifdef _WIN32
-#include <malloc.h>
-#elif ! defined(_MSC_VER)
+#if defined(HAVE_ALLOCA_H)
 #include <alloca.h>
+#elif defined(HAVE_MALLOC_H)
+#include <malloc.h>
 #endif
 #include <stdlib.h>
 #ifdef _MSC_VER
