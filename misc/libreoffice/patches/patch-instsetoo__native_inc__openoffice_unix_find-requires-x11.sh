$NetBSD: patch-instsetoo__native_inc__openoffice_unix_find-requires-x11.sh,v 1.1 2020/05/19 22:03:25 tnn Exp $

Shell compatibility

--- instsetoo_native/inc_openoffice/unix/find-requires-x11.sh.orig	2020-04-07 15:26:49.000000000 +0000
+++ instsetoo_native/inc_openoffice/unix/find-requires-x11.sh
@@ -18,8 +18,8 @@
 #
 
 cat > /dev/null
-[[ "${PLATFORMID}" == "linux_x86_64" ]] && mark64="()(64bit)"
-if [[ "${OS}" == "AIX" ]]; then
+[ "${PLATFORMID}" = "linux_x86_64" ] && mark64="()(64bit)"
+if [ "${OS}" = "AIX" ]; then
   echo "libfreetype.a(libfreetype.so.6${mark64})"
 else
   echo "libfreetype.so.6${mark64}"
