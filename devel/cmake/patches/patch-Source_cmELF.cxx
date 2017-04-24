$NetBSD: patch-Source_cmELF.cxx,v 1.6 2017/04/24 22:48:48 maya Exp $

Don't use DT_RUNPATH if it's not defined (netbsd-6)

--- Source/cmELF.cxx.orig	2017-04-10 15:23:07.000000000 +0000
+++ Source/cmELF.cxx
@@ -675,7 +675,11 @@ cmELF::StringEntry const* cmELFInternalI
 // External class implementation.
 
 const long cmELF::TagRPath = DT_RPATH;
+#ifdef DT_RUNPATH
 const long cmELF::TagRunPath = DT_RUNPATH;
+#else
+const long cmELF::TagRunPath = 0;
+#endif
 
 #ifdef DT_MIPS_RLD_MAP_REL
 const long cmELF::TagMipsRldMapRel = DT_MIPS_RLD_MAP_REL;
