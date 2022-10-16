$NetBSD: patch-instsetoo__native_inc__openoffice_unix_find-requires-x11.sh,v 1.5 2022/10/16 12:01:57 tnn Exp $

shell portability

--- instsetoo_native/inc_openoffice/unix/find-requires-x11.sh.orig	2022-09-09 18:45:51.000000000 +0000
+++ instsetoo_native/inc_openoffice/unix/find-requires-x11.sh
@@ -18,12 +18,12 @@
 #
 
 cat > /dev/null
-[[ "${PLATFORMID}" == "linux_x86_64" || "${PLATFORMID}" == "linux_aarch64" ]] && mark64="()(64bit)"
-if [[ "${OS}" == "AIX" ]]; then
+[ "${PLATFORMID}" = "linux_x86_64" -o "${PLATFORMID}" = "linux_aarch64" ] && mark64="()(64bit)"
+if [ "${OS}" = "AIX" ]; then
   echo "libfreetype.a(libfreetype.so.6${mark64})"
 else
   echo "libfreetype.so.6${mark64}"
-  if [[ "${XINERAMA_LINK}" == "dynamic" ]]; then
+  if [ "${XINERAMA_LINK}" = "dynamic" ]; then
     echo "libXinerama.so.1${mark64}"
   fi
 fi
