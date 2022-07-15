$NetBSD: patch-build_make_configure.sh,v 1.3 2022/07/15 11:04:33 adam Exp $

*BSD and qnx are identified as linux.
Add another SDK path on Mac OS X.
All sparc cpus can not do unaligned access.
Detect NetBSD ARMv7 hardfloat toolchain.
Recognize powerpc as a target ISA, so we don't end up with generic-gnu

--- build/make/configure.sh.orig	2022-06-28 19:00:48.000000000 +0000
+++ build/make/configure.sh
@@ -751,7 +751,7 @@ process_common_toolchain() {
       aarch64*)
         tgt_isa=arm64
         ;;
-      armv7*-hardfloat* | armv7*-gnueabihf | arm-*-gnueabihf)
+      armv7*-hardfloat* | armv7*-gnueabihf | arm-*-gnueabihf | armv7*-netbsd*-*hf)
         tgt_isa=armv7
         float_abi=hard
         ;;
@@ -783,6 +783,9 @@ process_common_toolchain() {
       loongarch64*)
         tgt_isa=loongarch64
         ;;
+      *powerpc*)
+	tgt_isa=powerpc
+	;;
     esac
 
     # detect tgt_os
@@ -805,7 +808,7 @@ process_common_toolchain() {
         [ -z "$tgt_isa" ] && tgt_isa=x86
         tgt_os=win32
         ;;
-      *linux*|*bsd*)
+      *linux*|*bsd*|*qnx6*)
         tgt_os=linux
         ;;
       *solaris2.10)
@@ -856,6 +859,9 @@ process_common_toolchain() {
       soft_enable lasx
       enable_feature loongarch
       ;;
+    sparc*)
+      disable_feature fast_unaligned
+      ;;
   esac
 
   # PIC is probably what we want when building shared libs
@@ -1506,7 +1512,7 @@ EOF
   check_cc <<EOF
 unsigned int e = 'O'<<24 | '2'<<16 | 'B'<<8 | 'E';
 EOF
-    [ -f "${TMP_O}" ] && od -A n -t x1 "${TMP_O}" | tr -d '\n' |
+    [ -f "${TMP_O}" ] && od -t x1 "${TMP_O}" | tr -d '\n' |
         grep '4f *32 *42 *45' >/dev/null 2>&1 && enable_feature big_endian
 
     # Try to find which inline keywords are supported
@@ -1523,7 +1529,7 @@ EOF
         # bionic includes basic pthread functionality, obviating -lpthread.
         ;;
       *)
-        check_header pthread.h && check_lib -lpthread <<EOF && add_extralibs -lpthread || disable_feature pthread_h
+        check_header pthread.h && check_lib ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS} <<EOF && add_extralibs ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS} || disable_feature pthread_h
 #include <pthread.h>
 #include <stddef.h>
 int main(void) { return pthread_create(NULL, NULL, NULL, NULL); }
