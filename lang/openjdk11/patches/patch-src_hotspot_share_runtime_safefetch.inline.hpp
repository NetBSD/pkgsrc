$NetBSD: patch-src_hotspot_share_runtime_safefetch.inline.hpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/runtime/safefetch.inline.hpp.orig	2025-04-19 23:57:10.000000000 +0000
+++ src/hotspot/share/runtime/safefetch.inline.hpp
@@ -32,7 +32,7 @@
 // to be valid. If the load causes a fault, the error value is returned.
 inline int SafeFetch32(int* adr, int errValue) {
   assert(StubRoutines::SafeFetch32_stub(), "stub not yet generated");
-#if defined(__APPLE__) && defined(AARCH64)
+#if defined(AARCH64)
   Thread* thread = Thread::current_or_null_safe();
   assert(thread != NULL, "required for W^X management");
   ThreadWXEnable wx(WXExec, thread);
@@ -42,7 +42,7 @@ inline int SafeFetch32(int* adr, int err
 
 inline intptr_t SafeFetchN(intptr_t* adr, intptr_t errValue) {
   assert(StubRoutines::SafeFetchN_stub(), "stub not yet generated");
-#if defined(__APPLE__) && defined(AARCH64)
+#if defined(AARCH64)
   Thread* thread = Thread::current_or_null_safe();
   assert(thread != NULL, "required for W^X management");
   ThreadWXEnable wx(WXExec, thread);
@@ -52,7 +52,7 @@ inline intptr_t SafeFetchN(intptr_t* adr
 
 // returns true if SafeFetch32 and SafeFetchN can be used safely (stubroutines are already generated)
 inline bool CanUseSafeFetch32() {
-#if defined (__APPLE__) && defined(AARCH64)
+#if defined(AARCH64)
   if (Thread::current_or_null_safe() == NULL) { // workaround for JDK-8282475
     return false;
   }
@@ -61,7 +61,7 @@ inline bool CanUseSafeFetch32() {
 }
 
 inline bool CanUseSafeFetchN() {
-#if defined (__APPLE__) && defined(AARCH64)
+#if defined(AARCH64)
   if (Thread::current_or_null_safe() == NULL) {
     return false;
   }
