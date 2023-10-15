$NetBSD: patch-instsetoo__native_inc__openoffice_unix_find-requires-x11.sh,v 1.6 2023/10/15 07:26:24 ryoon Exp $

shell portability

--- instsetoo_native/inc_openoffice/unix/find-requires-x11.sh.orig	2023-08-08 19:49:18.000000000 +0000
+++ instsetoo_native/inc_openoffice/unix/find-requires-x11.sh
@@ -18,8 +18,8 @@
 #
 
 cat > /dev/null
-[[ "${PLATFORMID}" == "linux_x86_64" || "${PLATFORMID}" == "linux_aarch64" ]] && mark64="()(64bit)"
+[ "${PLATFORMID}" = "linux_x86_64" -o "${PLATFORMID}" = "linux_aarch64" ] && mark64="()(64bit)"
 echo "libfreetype.so.6${mark64}"
-if [[ "${XINERAMA_LINK}" == "dynamic" ]]; then
+if [ "${XINERAMA_LINK}" = "dynamic" ]; then
   echo "libXinerama.so.1${mark64}"
 fi
