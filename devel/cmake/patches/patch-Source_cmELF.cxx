$NetBSD: patch-Source_cmELF.cxx,v 1.2 2015/01/17 13:29:55 adam Exp $

* SCO OpenServer 5.0.7/3.2 has not 64bit ELF support.

--- Source/cmELF.cxx.orig	2014-12-15 20:07:43.000000000 +0000
+++ Source/cmELF.cxx
@@ -49,6 +49,9 @@
 #if defined(__sun)
 # include <sys/link.h> // For dynamic section information
 #endif
+#if defined(_SCO_DS)
+# include <link.h> // For DT_SONAME etc.
+#endif
 
 //----------------------------------------------------------------------------
 // Low-level byte swapping implementation.
@@ -203,6 +206,8 @@ struct cmELFTypes32
 };
 
 // Configure the implementation template for 64-bit ELF files.
+#if !defined(_SCO_DS)
+// SCO OpenServer 5.0.7/3.2 does not support 64-bit ELF.
 struct cmELFTypes64
 {
   typedef Elf64_Ehdr ELF_Ehdr;
@@ -212,6 +217,7 @@ struct cmELFTypes64
   typedef cmIML_INT_uint64_t tagtype;
   static const char* GetName() { return "64-bit"; }
 };
+#endif
 
 //----------------------------------------------------------------------------
 // Parser implementation template.
@@ -788,11 +794,14 @@ cmELF::cmELF(const char* fname): Interna
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
