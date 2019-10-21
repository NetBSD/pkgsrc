$NetBSD: patch-ELF_Writer.cpp,v 1.3 2019/10/21 22:07:58 rjs Exp $

Add '-z nognustack' option to disable emitting PT_GNU_STACK.
https://reviews.llvm.org/D56554

--- ELF/Writer.cpp.orig	2019-09-06 11:20:15.000000000 +0000
+++ ELF/Writer.cpp
@@ -2160,14 +2160,16 @@ std::vector<PhdrEntry *> Writer<ELFT>::c
   if (OutputSection *cmd = findSection(".openbsd.randomdata", partNo))
     addHdr(PT_OPENBSD_RANDOMIZE, cmd->getPhdrFlags())->add(cmd);
 
-  // PT_GNU_STACK is a special section to tell the loader to make the
-  // pages for the stack non-executable. If you really want an executable
-  // stack, you can pass -z execstack, but that's not recommended for
-  // security reasons.
-  unsigned perm = PF_R | PF_W;
-  if (config->zExecstack)
-    perm |= PF_X;
-  addHdr(PT_GNU_STACK, perm)->p_memsz = config->zStackSize;
+  if (config->zGnustack != GnuStackKind::None) {
+    // PT_GNU_STACK is a special section to tell the loader to make the
+    // pages for the stack non-executable. If you really want an executable
+    // stack, you can pass -z execstack, but that's not recommended for
+    // security reasons.
+    unsigned perm = PF_R | PF_W;
+    if (config->zGnustack == GnuStackKind::Exec)
+      perm |= PF_X;
+    addHdr(PT_GNU_STACK, perm)->p_memsz = config->zStackSize;
+  }
 
   // PT_OPENBSD_WXNEEDED is a OpenBSD-specific header to mark the executable
   // is expected to perform W^X violations, such as calling mprotect(2) or
