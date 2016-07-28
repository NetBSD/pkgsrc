$NetBSD: patch-Source_cmELF.cxx,v 1.4 2016/07/28 17:44:43 prlw1 Exp $

* SCO OpenServer 5.0.7/3.2 has not 64bit ELF support.

--- Source/cmELF.cxx.orig	2016-07-07 14:47:27.000000000 +0000
+++ Source/cmELF.cxx
@@ -46,6 +46,9 @@ typedef struct Elf32_Rela Elf32_Rela;
 #if defined(__sun)
 #include <sys/link.h> // For dynamic section information
 #endif
+#if defined(_SCO_DS)
+# include <link.h> // For DT_SONAME etc.
+#endif
 
 // Low-level byte swapping implementation.
 template <size_t s>
@@ -214,6 +217,8 @@ struct cmELFTypes32
 };
 
 // Configure the implementation template for 64-bit ELF files.
+#if !defined(_SCO_DS)
+// SCO OpenServer 5.0.7/3.2 does not support 64-bit ELF.
 struct cmELFTypes64
 {
   typedef Elf64_Ehdr ELF_Ehdr;
@@ -223,6 +228,7 @@ struct cmELFTypes64
   typedef KWIML_INT_uint64_t tagtype;
   static const char* GetName() { return "64-bit"; }
 };
+#endif
 
 // Parser implementation template.
 template <class Types>
@@ -799,10 +805,15 @@ cmELF::cmELF(const char* fname)
   if (ident[EI_CLASS] == ELFCLASS32) {
     // 32-bit ELF
     this->Internal = new cmELFInternalImpl<cmELFTypes32>(this, fin, order);
-  } else if (ident[EI_CLASS] == ELFCLASS64) {
+  }
+#if !defined(_SCO_DS)
+// SCO OpenServer 5.0.7/3.2 does not support 64-bit ELF.
+  else if (ident[EI_CLASS] == ELFCLASS64) {
     // 64-bit ELF
     this->Internal = new cmELFInternalImpl<cmELFTypes64>(this, fin, order);
-  } else {
+  }
+#endif
+  else {
     this->ErrorMessage = "ELF file class is not 32-bit or 64-bit.";
     return;
   }
