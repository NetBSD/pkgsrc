$NetBSD: patch-vendor_openssl-src-300.5.0+3.5.0_src_lib.rs,v 1.2 2026/04/02 19:06:35 wiz Exp $

Make this build on NetBSD for arm6, mipsel and m68k as well.

--- vendor/openssl-src-300.5.0+3.5.0/src/lib.rs.orig	2026-02-11 07:30:54.000000000 +0000
+++ vendor/openssl-src-300.5.0+3.5.0/src/lib.rs
@@ -321,6 +321,7 @@ impl Build {
             "armv5te-unknown-linux-gnueabi" => "linux-armv4",
             "armv5te-unknown-linux-musleabi" => "linux-armv4",
             "armv6-unknown-freebsd" => "BSD-generic32",
+            "armv6-unknown-netbsd-eabihf" => "BSD-generic32",
             "armv6-alpine-linux-musleabihf" => "linux-armv6",
             "armv7-unknown-freebsd" => "BSD-armv4",
             "armv7-unknown-linux-gnueabi" => "linux-armv4",
@@ -348,6 +349,7 @@ impl Build {
             "i686-uwp-windows-msvc" => "VC-WIN32-UWP",
             "loongarch64-unknown-linux-gnu" => "linux-generic64",
             "loongarch64-unknown-linux-musl" => "linux-generic64",
+            "m68k-unknown-netbsd" => "NetBSD-generic32",
             "mips-unknown-linux-gnu" => "linux-mips32",
             "mips-unknown-linux-musl" => "linux-mips32",
             "mips64-unknown-linux-gnuabi64" => "linux64-mips64",
@@ -356,6 +358,7 @@ impl Build {
             "mips64el-unknown-linux-muslabi64" => "linux64-mips64",
             "mipsel-unknown-linux-gnu" => "linux-mips32",
             "mipsel-unknown-linux-musl" => "linux-mips32",
+            "mipsel-unknown-netbsd" => "NetBSD-generic32",
             "powerpc-unknown-freebsd" => "BSD-ppc",
             "powerpc-unknown-linux-gnu" => "linux-ppc",
             "powerpc-unknown-linux-gnuspe" => "linux-ppc",
