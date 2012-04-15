$NetBSD: patch-source_3rdparty_sge_depend_def.h,v 1.1 2012/04/15 04:07:21 markd Exp $

ensure varargs prototypes to fix build on 64bit

--- source/3rdparty/sge_depend/def.h.orig	2012-04-10 04:36:21.000000000 +0000
+++ source/3rdparty/sge_depend/def.h
@@ -170,6 +170,8 @@ int cppsetup();
 struct symtab **isdefined();
 #endif
 
+#define NeedVarargsPrototypes 1
+
 #if NeedVarargsPrototypes
 extern void fatalerr(char *, ...);
 extern void warning(char *, ...);
