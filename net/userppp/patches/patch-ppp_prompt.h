$NetBSD: patch-ppp_prompt.h,v 1.1 2011/11/26 17:18:57 joerg Exp $

--- ppp/prompt.h.orig	2011-11-26 03:04:37.000000000 +0000
+++ ppp/prompt.h
@@ -26,6 +26,8 @@
  * $FreeBSD: src/usr.sbin/ppp/prompt.h,v 1.6 2000/03/14 01:46:08 brian Exp $
  */
 
+#include <stdarg.h>
+
 #define LOCAL_AUTH	0x01
 #define LOCAL_NO_AUTH	0x02
 #define LOCAL_DENY	0x03
@@ -75,7 +77,7 @@ extern void prompt_Printf(struct prompt 
 #else
 extern void prompt_Printf(struct prompt *, const char *, ...);
 #endif
-extern void prompt_vPrintf(struct prompt *, const char *, _BSD_VA_LIST_);
+extern void prompt_vPrintf(struct prompt *, const char *, va_list);
 #define PROMPT_DONT_WANT_INT 1
 #define PROMPT_WANT_INT 0
 extern void prompt_TtyInit(struct prompt *);
