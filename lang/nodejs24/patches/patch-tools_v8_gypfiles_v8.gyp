$NetBSD: patch-tools_v8_gypfiles_v8.gyp,v 1.2 2026/11/22 14:36:14 kikadf Exp $

Add -larm on NetBSD ARM platforms.
Add trap-handler support for Open- and NetBSD on x64


--- tools/v8_gypfiles/v8.gyp.orig	2026-10-27 23:43:46.000000000 +0000
+++ tools/v8_gypfiles/v8.gyp
@@ -736,7 +736,7 @@
               }],
               ['v8_enable_webassembly==1', {
                 'conditions': [
-                  ['OS in "linux mac ios freebsd openharmony"', {
+                  ['OS in "linux mac ios freebsd openbsd netbsd openharmony"', {
                     'sources': [
                       '<(V8_ROOT)/src/trap-handler/handler-inside-posix.h',
                     ],
@@ -1156,7 +1156,7 @@
             }],
             ['v8_enable_webassembly==1', {
               'conditions': [
-                ['OS in "linux mac ios freebsd openharmony"', {
+                ['OS in "linux mac ios freebsd openbsd netbsd openharmony"', {
                   'sources': [
                     '<(V8_ROOT)/src/trap-handler/handler-inside-posix.cc',
                     '<(V8_ROOT)/src/trap-handler/handler-outside-posix.cc',
@@ -1326,6 +1326,12 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access.
+        # NetBSD/arm also needs -larm.
+        ['OS=="netbsd" and v8_current_cpu in ["arm"]', {
+          'link_settings': {
+            'libraries': ['-larm', ],
+          },
+        }],
         # Clang needs it for some atomic operations (https://clang.llvm.org/docs/Toolchain.html#atomics-library).
         ['(OS=="linux" and clang==1) or (v8_current_cpu in ["mips64", "mips64el", "arm", "riscv64", "loong64"])', {
           'link_settings': {
