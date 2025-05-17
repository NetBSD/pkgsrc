$NetBSD: patch-ext_google_protobuf__c_ruby-upb.h,v 1.1 2025/05/17 06:30:12 taca Exp $

Define UPB_SUPPRESS_MISSING_ATOMICS.

--- ext/google/protobuf_c/ruby-upb.h.orig	2025-05-16 02:39:03.487237531 +0000
+++ ext/google/protobuf_c/ruby-upb.h
@@ -2,6 +2,8 @@
 #define UPB_DISABLE_CLOSED_ENUM_CHECKING
 /* Amalgamated source file */
 
+#define UPB_SUPPRESS_MISSING_ATOMICS
+
 /*
  * This is where we define internal portability macros used across upb.
  *
