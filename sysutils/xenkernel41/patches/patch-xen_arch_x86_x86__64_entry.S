$NetBSD: patch-xen_arch_x86_x86__64_entry.S,v 1.1 2016/03/01 20:09:04 joerg Exp $

--- xen/arch/x86/x86_64/entry.S.orig	2016-02-29 20:42:10.767055585 +0000
+++ xen/arch/x86/x86_64/entry.S
@@ -51,7 +51,7 @@ restore_all_guest:
         addq  $8,%rsp
         popq  %rcx                    # RIP
         popq  %r11                    # CS
-        cmpw  $FLAT_USER_CS32,%r11
+        cmpw  $FLAT_USER_CS32,%r11w
         popq  %r11                    # RFLAGS
         popq  %rsp                    # RSP
         je    1f
