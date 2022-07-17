$NetBSD: patch-instsetoo__native_inc__openoffice_unix_find-requires-x11.sh,v 1.3 2022/07/17 10:58:12 tnn Exp $

shell portability

--- instsetoo_native/inc_openoffice/unix/find-requires-x11.sh.orig	2022-04-27 11:23:38.000000000 +0000
+++ instsetoo_native/inc_openoffice/unix/find-requires-x11.sh
@@ -18,8 +18,8 @@
 #
 
 cat > /dev/null
-[[ "${PLATFORMID}" == "linux_x86_64" || "${PLATFORMID}" == "linux_aarch64" ]] && mark64="()(64bit)"
-if [[ "${OS}" == "AIX" ]]; then
+[ "${PLATFORMID}" = "linux_x86_64" -o "${PLATFORMID}" = "linux_aarch64" ] && mark64="()(64bit)"
+if [ "${OS}" = "AIX" ]; then
   echo "libfreetype.a(libfreetype.so.6${mark64})"
 else
   echo "libfreetype.so.6${mark64}"
