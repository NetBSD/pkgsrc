$NetBSD: patch-hpijs.cpp,v 1.1 2015/04/26 13:28:23 joerg Exp $

--- hpijs.cpp.orig	2015-04-26 12:31:06.000000000 +0000
+++ hpijs.cpp
@@ -56,8 +56,8 @@ int bug(const char *fmt, ...)
    if ((n = vsnprintf(buf, 256, fmt, args)) == -1)
       buf[255] = 0;     /* output was truncated */
 
-   fprintf(stderr, buf);
-   syslog(LOG_WARNING, buf);
+   fprintf(stderr, "%s", buf);
+   syslog(LOG_WARNING, "%s", buf);
 
    fflush(stderr);
    va_end(args);
@@ -357,7 +357,7 @@ int hpijs_get_cb(void *get_cb_data, IjsS
    }
    else if (!strcmp (key, "ColorSpace"))
    {
-      return snprintf(value_buf, value_size, pSS->ph.cs);
+      return snprintf(value_buf, value_size, "%s", pSS->ph.cs);
    }
    else if (!strcmp (key, "PageImageFormat"))
    {
