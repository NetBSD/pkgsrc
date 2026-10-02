$NetBSD: patch-build_make_configure.sh,v 1.5 2026/10/02 05:07:45 adam Exp $

*BSD and qnx are identified as linux.
Add another SDK path on Mac OS X.
All sparc cpus can not do unaligned access.
Detect NetBSD ARMv7 hardfloat toolchain.
Recognize powerpc as a target ISA, so we don't end up with generic-gnu

--- build/make/configure.sh.orig	2026-08-20 19:06:35.000000000 +0000
+++ build/make/configure.sh
@@ -792,7 +792,7 @@ process_common_toolchain() {
       aarch64*)
         tgt_isa=arm64
         ;;
-      armv7*-hardfloat* | armv7*-gnueabihf | arm-*-gnueabihf)
+      armv7*-hardfloat* | armv7*-gnueabihf | arm-*-gnueabihf | armv7*-netbsd*-*hf)
         tgt_isa=armv7
         float_abi=hard
         ;;
@@ -824,6 +824,9 @@ process_common_toolchain() {
       loongarch64*)
         tgt_isa=loongarch64
         ;;
+      *powerpc*)
+	tgt_isa=powerpc
+	;;
     esac
 
     # detect tgt_os
@@ -846,7 +849,7 @@ process_common_toolchain() {
         [ -z "$tgt_isa" ] && tgt_isa=x86
         tgt_os=win32
         ;;
-      *linux*|*bsd*)
+      *linux*|*bsd*|*qnx6*)
         tgt_os=linux
         ;;
       *solaris2.10)
@@ -901,6 +904,9 @@ process_common_toolchain() {
       soft_enable lasx
       enable_feature loongarch
       ;;
+    sparc*)
+      disable_feature fast_unaligned
+      ;;
   esac
 
   # Position independent code (PIC) is probably what we want when building
@@ -1610,7 +1616,7 @@ EOF
   check_cc <<EOF
 unsigned int e = 'O'<<24 | '2'<<16 | 'B'<<8 | 'E';
 EOF
-    [ -f "${TMP_O}" ] && od -A n -t x1 "${TMP_O}" | tr -d '\n' |
+    [ -f "${TMP_O}" ] && od -t x1 "${TMP_O}" | tr -d '\n' |
         grep '4f *32 *42 *45' >/dev/null 2>&1 && enable_feature big_endian
 
     # Try to find which inline keywords are supported
@@ -1628,7 +1634,7 @@ EOF
         soft_enable pthread_setname_np
         ;;
       *)
-        check_header pthread.h && check_lib -lpthread <<EOF && add_extralibs -lpthread || disable_feature pthread_h
+        check_header pthread.h && check_lib ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS} <<EOF && add_extralibs ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS} || disable_feature pthread_h
 #include <pthread.h>
 #include <stddef.h>
 int main(void) { return pthread_create(NULL, NULL, NULL, NULL); }
