$NetBSD: patch-mozilla_toolkit_components_osfile_osfile__unix__allthreads.jsm,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/toolkit/components/osfile/osfile_unix_allthreads.jsm.orig	2013-10-23 22:09:18.000000000 +0000
+++ mozilla/toolkit/components/osfile/osfile_unix_allthreads.jsm
@@ -40,7 +40,7 @@ if (typeof Components != "undefined") {
   // Open libc
   let libc;
   let libc_candidates =  [ "libSystem.B.dylib",
-                           "libc.so.6",
+                           "libc.so.7",
                            "libc.so" ];
   for (let i = 0; i < libc_candidates.length; ++i) {
     try {
