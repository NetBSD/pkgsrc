$NetBSD: patch-.._vendor_openssl-src-111.25.0+1.1.1t_src_lib.rs,v 1.1 2023/12/03 20:48:21 pin Exp $

Allow building on NetBSD and provide defaults for the various targets.

--- ../vendor/openssl-src-111.25.0+1.1.1t/src/lib.rs.orig	2023-12-03 19:58:29.333847687 +0000
+++ ../vendor/openssl-src-111.25.0+1.1.1t/src/lib.rs
@@ -238,6 +238,8 @@ impl Build {
             "aarch64-unknown-freebsd" => "BSD-generic64",
             "aarch64-unknown-linux-gnu" => "linux-aarch64",
             "aarch64-unknown-linux-musl" => "linux-aarch64",
+            "aarch64-unknown-netbsd" => "BSD-generic64",
+            "aarch64_be-unknown-netbsd" => "BSD-generic64",
             "aarch64-pc-windows-msvc" => "VC-WIN64-ARM",
             "arm-linux-androideabi" => "linux-armv4",
             "armv7-linux-androideabi" => "linux-armv4",
@@ -245,6 +247,7 @@ impl Build {
             "arm-unknown-linux-gnueabihf" => "linux-armv4",
             "arm-unknown-linux-musleabi" => "linux-armv4",
             "arm-unknown-linux-musleabihf" => "linux-armv4",
+            "armv7-unknown-netbsd-eabihf" => "BSD-generic32",
             "armv5te-unknown-linux-gnueabi" => "linux-armv4",
             "armv5te-unknown-linux-musleabi" => "linux-armv4",
             "armv6-unknown-freebsd" => "BSD-generic32",
@@ -256,6 +259,7 @@ impl Build {
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
@@ -276,12 +281,14 @@ impl Build {
             "powerpc64-unknown-freebsd" => "BSD-generic64",
             "powerpc64-unknown-linux-gnu" => "linux-ppc64",
             "powerpc64-unknown-linux-musl" => "linux-ppc64",
+            "powerpc-unknown-netbsd" => "BSD-generic32",
             "powerpc64le-unknown-freebsd" => "BSD-generic64",
             "powerpc64le-unknown-linux-gnu" => "linux-ppc64le",
             "powerpc64le-unknown-linux-musl" => "linux-ppc64le",
             "riscv64gc-unknown-linux-gnu" => "linux-generic64",
             "s390x-unknown-linux-gnu" => "linux64-s390x",
             "s390x-unknown-linux-musl" => "linux64-s390x",
+            "sparc64-unknown-netbsd" => "BSD-generic64",
             "x86_64-apple-darwin" => "darwin64-x86_64-cc",
             "x86_64-linux-android" => "linux-x86_64",
             "x86_64-pc-windows-gnu" => "mingw64",
