$NetBSD: patch-Source_cmELF.cxx,v 1.1 2014/07/17 13:44:28 ryoon Exp $

* SCO OpenServer 5.0.7/3.2 has not 64bit ELF support.

--- Source/cmELF.cxx.orig	2014-01-16 17:15:08.000000000 +0000
+++ Source/cmELF.cxx
@@ -28,6 +28,9 @@
 #if defined(__sun)
 # include <sys/link.h> // For dynamic section information
 #endif
+#if defined(_SCO_DS)
+# include <link.h> // For DT_SONAME etc.
+#endif
 
 //----------------------------------------------------------------------------
 // Low-level byte swapping implementation.
@@ -181,6 +184,8 @@ struct cmELFTypes32
 };
 
 // Configure the implementation template for 32-bit ELF files.
+#if !defined(_SCO_DS)
+// SCO OpenServer 5.0.7/3.2 has not 64bit ELF support.
 struct cmELFTypes64
 {
   typedef Elf64_Ehdr ELF_Ehdr;
@@ -189,6 +194,7 @@ struct cmELFTypes64
   typedef Elf64_Half ELF_Half;
   static const char* GetName() { return "64-bit"; }
 };
+#endif
 
 //----------------------------------------------------------------------------
 // Parser implementation template.
@@ -764,11 +770,14 @@ cmELF::cmELF(const char* fname): Interna
     // 32-bit ELF
     this->Internal = new cmELFInternalImpl<cmELFTypes32>(this, fin, order);
     }
+#if !defined(_SCO_DS)
+// SCO OpenServer 5.0.7/3.2 has not 64bit ELF support.
   else if(ident[EI_CLASS] == ELFCLASS64)
     {
     // 64-bit ELF
     this->Internal = new cmELFInternalImpl<cmELFTypes64>(this, fin, order);
     }
+#endif
   else
     {
     this->ErrorMessage = "ELF file class is not 32-bit or 64-bit.";
