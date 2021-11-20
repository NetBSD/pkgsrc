$NetBSD: patch-vendor_openssl-src_src_lib.rs,v 1.6 2021/11/20 16:09:46 he Exp $

Provide defaults for the various NetBSD targets.

--- vendor/openssl-src/src/lib.rs.orig	2021-07-26 15:20:39.000000000 +0000
+++ vendor/openssl-src/src/lib.rs
@@ -219,6 +219,8 @@ impl Build {
             "aarch64-unknown-freebsd" => "BSD-generic64",
             "aarch64-unknown-linux-gnu" => "linux-aarch64",
             "aarch64-unknown-linux-musl" => "linux-aarch64",
+            "aarch64-unknown-netbsd" => "BSD-generic64",
+            "aarch64_be-unknown-netbsd" => "BSD-generic64",
             "aarch64-pc-windows-msvc" => "VC-WIN64-ARM",
             "arm-linux-androideabi" => "linux-armv4",
             "armv7-linux-androideabi" => "linux-armv4",
@@ -234,6 +236,7 @@ impl Build {
             "armv7-unknown-linux-musleabi" => "linux-armv4",
             "armv7-unknown-linux-gnueabihf" => "linux-armv4",
             "armv7-unknown-linux-musleabihf" => "linux-armv4",
+            "armv7-unknown-netbsd-eabihf" => "BSD-generic32",
             "asmjs-unknown-emscripten" => "gcc",
             "i586-unknown-linux-gnu" => "linux-elf",
             "i586-unknown-linux-musl" => "linux-elf",
@@ -244,6 +247,8 @@ impl Build {
             "i686-unknown-freebsd" => "BSD-x86-elf",
             "i686-unknown-linux-gnu" => "linux-elf",
             "i686-unknown-linux-musl" => "linux-elf",
+            "i686-unknown-netbsd" => "BSD-x86-elf",
+            "i586-unknown-netbsd" => "BSD-x86-elf",
             "mips-unknown-linux-gnu" => "linux-mips32",
             "mips-unknown-linux-musl" => "linux-mips32",
             "mips64-unknown-linux-gnuabi64" => "linux64-mips64",
@@ -254,6 +259,7 @@ impl Build {
             "mipsel-unknown-linux-musl" => "linux-mips32",
             "powerpc-unknown-freebsd" => "BSD-generic32",
             "powerpc-unknown-linux-gnu" => "linux-ppc",
+            "powerpc-unknown-netbsd" => "BSD-generic32",
             "powerpc64-unknown-freebsd" => "BSD-generic64",
             "powerpc64-unknown-linux-gnu" => "linux-ppc64",
             "powerpc64-unknown-linux-musl" => "linux-ppc64",
@@ -263,6 +269,7 @@ impl Build {
             "riscv64gc-unknown-linux-gnu" => "linux-generic64",
             "s390x-unknown-linux-gnu" => "linux64-s390x",
             "s390x-unknown-linux-musl" => "linux64-s390x",
+            "sparc64-unknown-netbsd" => "BSD-generic64",
             "x86_64-apple-darwin" => "darwin64-x86_64-cc",
             "x86_64-linux-android" => "linux-x86_64",
             "x86_64-pc-windows-gnu" => "mingw64",
