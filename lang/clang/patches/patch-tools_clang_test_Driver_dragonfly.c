$NetBSD: patch-tools_clang_test_Driver_dragonfly.c,v 1.1 2012/11/29 11:42:25 marino Exp $

Update DragonFly driver test to reflect the current reality

--- tools/clang/test/Driver/dragonfly.c.orig	2012-01-24 01:55:55.000000000 +0000
+++ tools/clang/test/Driver/dragonfly.c
@@ -1,7 +1,7 @@
-// RUN: %clang -no-canonical-prefixes -target amd64-pc-dragonfly %s -### 2> %t.log
+// RUN: %clang -no-canonical-prefixes -target x86_64-pc-dragonfly %s -### 2> %t.log
 // RUN: FileCheck -input-file %t.log %s
 
-// CHECK: clang{{.*}}" "-cc1" "-triple" "amd64-pc-dragonfly"
-// CHECK: ld{{.*}}" "-dynamic-linker" "{{.*}}ld-elf.{{.*}}" "-o" "a.out" "{{.*}}crt1.o" "{{.*}}crti.o" "{{.*}}crtbegin.o" "{{.*}}.o" "-L{{.*}}/gcc{{.*}}" {{.*}} "-lc" "-lgcc" "{{.*}}crtend.o" "{{.*}}crtn.o"
+// CHECK: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-dragonfly"
+// CHECK: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/usr/libexec/ld-elf.so.{{.*}}" "--hash-style=both" "-o" "a.out" "/usr/lib/crt1.o" "/usr/lib/crti.o" "{{.*}}crtbegin.o" "{{.*}}.o" "-L/usr/lib/gcc4{{.*}}" "-rpath" "/usr/lib/gcc4{{.*}}" "-lc" "-lgcc" "{{.*}}crtend.o" "/usr/lib/crtn.o"
 
 
