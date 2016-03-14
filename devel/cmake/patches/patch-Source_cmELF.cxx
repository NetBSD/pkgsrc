$NetBSD: patch-Source_cmELF.cxx,v 1.3 2016/03/14 10:49:55 adam Exp $

* SCO OpenServer 5.0.7/3.2 has not 64bit ELF support.

--- Source/cmELF.cxx.orig	2016-03-08 14:36:22.000000000 +0000
+++ Source/cmELF.cxx
@@ -45,6 +45,9 @@
 #if defined(__sun)
 # include <sys/link.h> // For dynamic section information
 #endif
+#if defined(_SCO_DS)
+# include <link.h> // For DT_SONAME etc.
+#endif
 
 //----------------------------------------------------------------------------
 // Low-level byte swapping implementation.
@@ -199,6 +202,8 @@ struct cmELFTypes32
 };
 
 // Configure the implementation template for 64-bit ELF files.
+#if !defined(_SCO_DS)
+// SCO OpenServer 5.0.7/3.2 does not support 64-bit ELF.
 struct cmELFTypes64
 {
   typedef Elf64_Ehdr ELF_Ehdr;
@@ -208,6 +213,7 @@ struct cmELFTypes64
   typedef KWIML_INT_uint64_t tagtype;
   static const char* GetName() { return "64-bit"; }
 };
+#endif
 
 //----------------------------------------------------------------------------
 // Parser implementation template.
@@ -790,11 +796,14 @@ cmELF::cmELF(const char* fname): Interna
     // 32-bit ELF
     this->Internal = new cmELFInternalImpl<cmELFTypes32>(this, fin, order);
     }
+#if !defined(_SCO_DS)
+// SCO OpenServer 5.0.7/3.2 does not support 64-bit ELF.
   else if(ident[EI_CLASS] == ELFCLASS64)
     {
     // 64-bit ELF
     this->Internal = new cmELFInternalImpl<cmELFTypes64>(this, fin, order);
     }
+#endif
   else
     {
     this->ErrorMessage = "ELF file class is not 32-bit or 64-bit.";
