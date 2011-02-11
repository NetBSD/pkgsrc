$NetBSD: patch-src_lib_util_astring.h,v 1.2 2011/02/11 12:49:33 abs Exp $

--- src/lib/util/astring.h.orig	2010-10-31 23:48:04.000000000 +0000
+++ src/lib/util/astring.h
@@ -296,6 +296,10 @@ INLINE astring *astring_assemble_5(astri
 ***************************************************************************/
 
 #ifdef __cplusplus
+#ifdef SDLMAME_NETBSD
+#undef toupper
+#undef tolower
+#endif
 
 /* derived class for C++ */
 class astring : public astring_base
