$NetBSD: patch-.._vendor_openssl-src_111.24.0+1.1.1s_src_lib.rs,v 1.1 2022/11/22 20:18:06 pin Exp $

Add recognition of the various rust-supporting NetBSD variants.

--- ../vendor/openssl-src-111.24.0+1.1.1s/src/lib.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/openssl-src-111.24.0+1.1.1s/src/lib.rs
@@ -239,6 +239,8 @@ impl Build {
             "aarch64-unknown-linux-gnu" => "linux-aarch64",
             "aarch64-unknown-linux-musl" => "linux-aarch64",
             "aarch64-pc-windows-msvc" => "VC-WIN64-ARM",
+            "aarch64-unknown-netbsd" => "BSD-generic64",
+            "aarch64_be-unknown-netbsd" => "BSD-generic64",
             "arm-linux-androideabi" => "linux-armv4",
             "armv7-linux-androideabi" => "linux-armv4",
             "arm-unknown-linux-gnueabi" => "linux-armv4",
@@ -251,11 +253,13 @@ impl Build {
             "armv7-unknown-freebsd" => "BSD-generic32",
             "armv7-unknown-linux-gnueabi" => "linux-armv4",
             "armv7-unknown-linux-musleabi" => "linux-armv4",
+            "armv7-unknown-netbsd-eabihf" => "BSD-generic32",
             "armv7-unknown-linux-gnueabihf" => "linux-armv4",
             "armv7-unknown-linux-musleabihf" => "linux-armv4",
             "asmjs-unknown-emscripten" => "gcc",
             "i586-unknown-linux-gnu" => "linux-elf",
             "i586-unknown-linux-musl" => "linux-elf",
+            "i586-unknown-netbsd" => "BSD-x86-elf",
             "i686-apple-darwin" => "darwin-i386-cc",
             "i686-linux-android" => "linux-elf",
             "i686-pc-windows-gnu" => "mingw",
@@ -263,6 +267,7 @@ impl Build {
             "i686-unknown-freebsd" => "BSD-x86-elf",
             "i686-unknown-linux-gnu" => "linux-elf",
             "i686-unknown-linux-musl" => "linux-elf",
+            "i686-unknown-netbsd" => "BSD-x86-elf",
             "mips-unknown-linux-gnu" => "linux-mips32",
             "mips-unknown-linux-musl" => "linux-mips32",
             "mips64-unknown-linux-gnuabi64" => "linux64-mips64",
@@ -273,6 +278,7 @@ impl Build {
             "mipsel-unknown-linux-musl" => "linux-mips32",
             "powerpc-unknown-freebsd" => "BSD-generic32",
             "powerpc-unknown-linux-gnu" => "linux-ppc",
+            "powerpc-unknown-netbsd" => "BSD-generic32",
             "powerpc64-unknown-freebsd" => "BSD-generic64",
             "powerpc64-unknown-linux-gnu" => "linux-ppc64",
             "powerpc64-unknown-linux-musl" => "linux-ppc64",
@@ -282,6 +288,7 @@ impl Build {
             "riscv64gc-unknown-linux-gnu" => "linux-generic64",
             "s390x-unknown-linux-gnu" => "linux64-s390x",
             "s390x-unknown-linux-musl" => "linux64-s390x",
+            "sparc64-unknown-netbsd" => "BSD-generic64",
             "x86_64-apple-darwin" => "darwin64-x86_64-cc",
             "x86_64-linux-android" => "linux-x86_64",
             "x86_64-pc-windows-gnu" => "mingw64",
