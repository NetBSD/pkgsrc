$NetBSD: patch-ELF_Writer.cpp,v 1.1 2019/02/01 16:30:00 mgorny Exp $

Add '-z nognustack' option to disable emitting PT_GNU_STACK.
https://reviews.llvm.org/D56554

Alter defaults for NetBSD targets:
* disable PT_GNU_STACK (meaningless on NetBSD)

--- ELF/Writer.cpp.orig	2018-10-31 17:14:17.000000000 +0000
+++ ELF/Writer.cpp
@@ -1881,14 +1881,16 @@ template <class ELFT> std::vector<PhdrEn
   if (OutputSection *Cmd = findSection(".openbsd.randomdata"))
     AddHdr(PT_OPENBSD_RANDOMIZE, Cmd->getPhdrFlags())->add(Cmd);
 
-  // PT_GNU_STACK is a special section to tell the loader to make the
-  // pages for the stack non-executable. If you really want an executable
-  // stack, you can pass -z execstack, but that's not recommended for
-  // security reasons.
-  unsigned Perm = PF_R | PF_W;
-  if (Config->ZExecstack)
-    Perm |= PF_X;
-  AddHdr(PT_GNU_STACK, Perm)->p_memsz = Config->ZStackSize;
+  if (!Config->ZNognustack) {
+    // PT_GNU_STACK is a special section to tell the loader to make the
+    // pages for the stack non-executable. If you really want an executable
+    // stack, you can pass -z execstack, but that's not recommended for
+    // security reasons.
+    unsigned Perm = PF_R | PF_W;
+    if (Config->ZExecstack)
+      Perm |= PF_X;
+    AddHdr(PT_GNU_STACK, Perm)->p_memsz = Config->ZStackSize;
+  }
 
   // PT_OPENBSD_WXNEEDED is a OpenBSD-specific header to mark the executable
   // is expected to perform W^X violations, such as calling mprotect(2) or
