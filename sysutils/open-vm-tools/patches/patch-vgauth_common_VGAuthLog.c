$NetBSD: patch-vgauth_common_VGAuthLog.c,v 1.2 2016/10/12 13:57:13 ryoon Exp $

--- vgauth/common/VGAuthLog.c.orig	2016-02-16 20:06:48.000000000 +0000
+++ vgauth/common/VGAuthLog.c
@@ -210,7 +210,7 @@ LogErrorPosixCodeV(int code,
    g_vsnprintf(buf, sizeof buf, fmt, args);
    buf[sizeof buf - 1] = '\0';
 
-#ifdef sun
+#if defined(sun) || defined(__NetBSD__)
    strerror_r(code, errMsg, sizeof errMsg);
    g_warning("[function %s, file %s, line %d], %s, [errno = %d], %s\n",
              func, file, line, buf, code, errMsg);
