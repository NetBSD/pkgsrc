$NetBSD: patch-vendor_openssl-src-111.22.0+1.1.1q_src_lib.rs,v 1.1 2022/10/21 11:40:40 pin Exp $

Allow building on NetBSD and provide defaults for the various targets.

--- ../vendor/openssl-src-111.22.0+1.1.1q/src/lib.rs.orig	1973-11-29 21:33:09.000000000 +0000
+++ ../vendor/openssl-src-111.22.0+1.1.1q/src/lib.rs
@@ -55,6 +55,7 @@ impl Build {
         let host = &self.host.as_ref().expect("HOST dir not set")[..];
         if host.contains("dragonfly")
             || host.contains("freebsd")
+            || host.contains("netbsd")
             || host.contains("openbsd")
             || host.contains("solaris")
             || host.contains("illumos")
@@ -228,6 +229,7 @@ impl Build {
             // out and say it's linux and hope it works.
             "aarch64-linux-android" => "linux-aarch64",
             "aarch64-unknown-freebsd" => "BSD-generic64",
+            "aarch64-unknown-netbsd" => "BSD-generic64",
             "aarch64-unknown-linux-gnu" => "linux-aarch64",
             "aarch64-unknown-linux-musl" => "linux-aarch64",
             "aarch64-pc-windows-msvc" => "VC-WIN64-ARM",
@@ -240,7 +242,9 @@ impl Build {
             "armv5te-unknown-linux-gnueabi" => "linux-armv4",
             "armv5te-unknown-linux-musleabi" => "linux-armv4",
             "armv6-unknown-freebsd" => "BSD-generic32",
+            "armv6-unknown-netbsd" => "BSD-generic32",
             "armv7-unknown-freebsd" => "BSD-generic32",
+            "armv7-unknown-netbsd" => "BSD-generic32",
             "armv7-unknown-linux-gnueabi" => "linux-armv4",
             "armv7-unknown-linux-musleabi" => "linux-armv4",
             "armv7-unknown-linux-gnueabihf" => "linux-armv4",
@@ -253,6 +257,7 @@ impl Build {
             "i686-pc-windows-gnu" => "mingw",
             "i686-pc-windows-msvc" => "VC-WIN32",
             "i686-unknown-freebsd" => "BSD-x86-elf",
+            "i686-unknown-netbsd" => "BSD-x86-elf",
             "i686-unknown-linux-gnu" => "linux-elf",
             "i686-unknown-linux-musl" => "linux-elf",
             "mips-unknown-linux-gnu" => "linux-mips32",
@@ -264,11 +269,14 @@ impl Build {
             "mipsel-unknown-linux-gnu" => "linux-mips32",
             "mipsel-unknown-linux-musl" => "linux-mips32",
             "powerpc-unknown-freebsd" => "BSD-generic32",
+            "powerpc-unknown-netbsd" => "BSD-generic32",
             "powerpc-unknown-linux-gnu" => "linux-ppc",
             "powerpc64-unknown-freebsd" => "BSD-generic64",
+            "powerpc64-unknown-netbsd" => "BSD-generic64",
             "powerpc64-unknown-linux-gnu" => "linux-ppc64",
             "powerpc64-unknown-linux-musl" => "linux-ppc64",
             "powerpc64le-unknown-freebsd" => "BSD-generic64",
+            "powerpc64le-unknown-netbsd" => "BSD-generic64",
             "powerpc64le-unknown-linux-gnu" => "linux-ppc64le",
             "powerpc64le-unknown-linux-musl" => "linux-ppc64le",
             "riscv64gc-unknown-linux-gnu" => "linux-generic64",
@@ -279,6 +287,7 @@ impl Build {
             "x86_64-pc-windows-gnu" => "mingw64",
             "x86_64-pc-windows-msvc" => "VC-WIN64A",
             "x86_64-unknown-freebsd" => "BSD-x86_64",
+            "x86_64-unknown-netbsd" => "BSD-x86_64",
             "x86_64-unknown-dragonfly" => "BSD-x86_64",
             "x86_64-unknown-illumos" => "solaris64-x86_64-gcc",
             "x86_64-unknown-linux-gnu" => "linux-x86_64",
