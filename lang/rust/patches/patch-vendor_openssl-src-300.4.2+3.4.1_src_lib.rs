$NetBSD: patch-vendor_openssl-src-300.4.2+3.4.1_src_lib.rs,v 1.1 2025/08/25 17:51:13 wiz Exp $

Make this build on NetBSD for arm64 and mipsel as well.

--- vendor/openssl-src-300.4.2+3.4.1/src/lib.rs.orig	2025-05-18 21:45:55.955282328 +0000
+++ vendor/openssl-src-300.4.2+3.4.1/src/lib.rs
@@ -321,6 +321,7 @@ impl Build {
             "armv5te-unknown-linux-gnueabi" => "linux-armv4",
             "armv5te-unknown-linux-musleabi" => "linux-armv4",
             "armv6-unknown-freebsd" => "BSD-generic32",
+            "armv6-unknown-netbsd-eabihf" => "BSD-generic32",
             "armv6-alpine-linux-musleabihf" => "linux-armv6",
             "armv7-unknown-freebsd" => "BSD-armv4",
             "armv7-unknown-linux-gnueabi" => "linux-armv4",
@@ -356,6 +357,7 @@ impl Build {
             "mips64el-unknown-linux-muslabi64" => "linux64-mips64",
             "mipsel-unknown-linux-gnu" => "linux-mips32",
             "mipsel-unknown-linux-musl" => "linux-mips32",
+            "mipsel-unknown-netbsd" => "NetBSD-generic32",
             "powerpc-unknown-freebsd" => "BSD-ppc",
             "powerpc-unknown-linux-gnu" => "linux-ppc",
             "powerpc-unknown-linux-gnuspe" => "linux-ppc",
