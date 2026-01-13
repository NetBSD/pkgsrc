$NetBSD: patch-vendor_openssl-src-300.5.2+3.5.2_src_lib.rs,v 1.1 2026/01/13 20:48:23 wiz Exp $

Make this build on NetBSD for armv6 and mipsel as well.

--- vendor/openssl-src-300.5.2+3.5.2/src/lib.rs.orig	2025-11-02 17:17:16.773220231 +0000
+++ vendor/openssl-src-300.5.2+3.5.2/src/lib.rs
@@ -326,6 +326,7 @@ impl Build {
             "armv5te-unknown-linux-gnueabi" => "linux-armv4",
             "armv5te-unknown-linux-musleabi" => "linux-armv4",
             "armv6-unknown-freebsd" => "BSD-generic32",
+            "armv6-unknown-netbsd-eabihf" => "BSD-generic32",
             "armv6-alpine-linux-musleabihf" => "linux-armv6",
             "armv7-unknown-freebsd" => "BSD-armv4",
             "armv7-unknown-linux-gnueabi" => "linux-armv4",
@@ -361,6 +362,7 @@ impl Build {
             "mips64el-unknown-linux-muslabi64" => "linux64-mips64",
             "mipsel-unknown-linux-gnu" => "linux-mips32",
             "mipsel-unknown-linux-musl" => "linux-mips32",
+            "mipsel-unknown-netbsd" => "NetBSD-generic32",
             "powerpc-unknown-freebsd" => "BSD-ppc",
             "powerpc-unknown-linux-gnu" => "linux-ppc",
             "powerpc-unknown-linux-gnuspe" => "linux-ppc",
