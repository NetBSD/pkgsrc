$NetBSD: patch-elf_object-file.cc,v 1.1 2022/01/19 02:52:24 pho Exp $

It should be perfectly legal to have an empty CIE along with an end-of-records
marker of FDE. /usr/lib/crtend.o from NetBSD/amd64 has the following .eh_frame
but mold emits an error for the zero-length FDE:

    .section	.eh_frame, "a", @progbits
    .align 8
    .quad 0

PR sent to the upstream:
https://github.com/rui314/mold/pull/278

--- elf/object-file.cc.orig	2021-12-31 05:10:03.000000000 +0000
+++ elf/object-file.cc
@@ -322,9 +322,8 @@ void ObjectFile<E>::read_ehframe(Context
   for (std::string_view data = contents; !data.empty();) {
     i64 size = *(u32 *)data.data();
     if (size == 0) {
-      if (data.size() != 4)
-        Fatal(ctx) << isec << ": garbage at end of section";
-      break;
+      data = data.substr(4);
+      continue;
     }
 
     i64 begin_offset = data.data() - contents.data();
