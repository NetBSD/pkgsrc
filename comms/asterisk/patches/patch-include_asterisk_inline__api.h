$NetBSD: patch-include_asterisk_inline__api.h,v 1.1 2012/05/04 16:06:13 joerg Exp $

--- include/asterisk/inline_api.h.orig	2006-02-14 19:14:15.000000000 +0000
+++ include/asterisk/inline_api.h
@@ -46,7 +46,11 @@
 #if !defined(LOW_MEMORY)
 
 #if !defined(AST_API_MODULE)
-#define AST_INLINE_API(hdr, body) hdr; extern inline hdr body
+# ifndef __GNUC_STDC_INLINE__
+# define AST_INLINE_API(hdr, body) hdr; extern inline hdr body
+# else
+# define AST_INLINE_API(hdr, body) inline hdr body
+# endif
 #else
 #define AST_INLINE_API(hdr, body) hdr; hdr body
 #endif
