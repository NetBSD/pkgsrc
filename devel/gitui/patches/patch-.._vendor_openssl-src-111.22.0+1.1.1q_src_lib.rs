$NetBSD: patch-.._vendor_openssl-src-111.22.0+1.1.1q_src_lib.rs,v 1.1 2022/09/20 19:30:51 wiz Exp $

Add recognition of the various rust-supporting NetBSD variants.

--- ../vendor/openssl-src-111.22.0+1.1.1q/src/lib.rs.orig	2022-09-18 20:18:31.577292069 +0000
+++ ../vendor/openssl-src-111.22.0+1.1.1q/src/lib.rs
@@ -230,6 +230,8 @@ impl Build {
             "aarch64-unknown-freebsd" => "BSD-generic64",
             "aarch64-unknown-linux-gnu" => "linux-aarch64",
             "aarch64-unknown-linux-musl" => "linux-aarch64",
+            "aarch64-unknown-netbsd" => "BSD-generic64",
+            "aarch64_be-unknown-netbsd" => "BSD-generic64",
             "aarch64-pc-windows-msvc" => "VC-WIN64-ARM",
             "arm-linux-androideabi" => "linux-armv4",
             "armv7-linux-androideabi" => "linux-armv4",
@@ -245,9 +247,11 @@ impl Build {
             "armv7-unknown-linux-musleabi" => "linux-armv4",
             "armv7-unknown-linux-gnueabihf" => "linux-armv4",
             "armv7-unknown-linux-musleabihf" => "linux-armv4",
+            "armv7-unknown-netbsd-eabihf" => "BSD-generic32",
             "asmjs-unknown-emscripten" => "gcc",
             "i586-unknown-linux-gnu" => "linux-elf",
             "i586-unknown-linux-musl" => "linux-elf",
+            "i586-unknown-netbsd" => "BSD-x86-elf",
             "i686-apple-darwin" => "darwin-i386-cc",
             "i686-linux-android" => "linux-elf",
             "i686-pc-windows-gnu" => "mingw",
@@ -255,6 +259,7 @@ impl Build {
             "i686-unknown-freebsd" => "BSD-x86-elf",
             "i686-unknown-linux-gnu" => "linux-elf",
             "i686-unknown-linux-musl" => "linux-elf",
+            "i686-unknown-netbsd" => "BSD-x86-elf",
             "mips-unknown-linux-gnu" => "linux-mips32",
             "mips-unknown-linux-musl" => "linux-mips32",
             "mips64-unknown-linux-gnuabi64" => "linux64-mips64",
@@ -265,6 +270,7 @@ impl Build {
             "mipsel-unknown-linux-musl" => "linux-mips32",
             "powerpc-unknown-freebsd" => "BSD-generic32",
             "powerpc-unknown-linux-gnu" => "linux-ppc",
+            "powerpc-unknown-netbsd" => "BSD-generic32",
             "powerpc64-unknown-freebsd" => "BSD-generic64",
             "powerpc64-unknown-linux-gnu" => "linux-ppc64",
             "powerpc64-unknown-linux-musl" => "linux-ppc64",
@@ -274,6 +280,7 @@ impl Build {
             "riscv64gc-unknown-linux-gnu" => "linux-generic64",
             "s390x-unknown-linux-gnu" => "linux64-s390x",
             "s390x-unknown-linux-musl" => "linux64-s390x",
+            "sparc64-unknown-netbsd" => "BSD-generic64",
             "x86_64-apple-darwin" => "darwin64-x86_64-cc",
             "x86_64-linux-android" => "linux-x86_64",
             "x86_64-pc-windows-gnu" => "mingw64",
