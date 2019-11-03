$NetBSD: patch-ELF_Writer.cpp,v 1.5 2019/11/03 12:40:40 kamil Exp $

Cherry-pick upstream patch commit 2a0fcae3d4d1fd85d6ae8378d7c6f12430c0087d
[lld] [ELF] Add '-z nognustack' opt to suppress emitting PT_GNU_STACK

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
