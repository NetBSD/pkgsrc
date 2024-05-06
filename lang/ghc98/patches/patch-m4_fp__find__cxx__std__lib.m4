$NetBSD: patch-m4_fp__find__cxx__std__lib.m4,v 1.1 2024/05/06 02:26:40 pho Exp $

$CXX must not be quoted because it may contain flags. The same goes for
$CC. This causes a configuration failure on MacOS X 14 where AC_PROG_CXX
sets $CXX to "clang++ -std=gnu++11".

TODO: Upstream this.

--- m4/fp_find_cxx_std_lib.m4.orig	2024-05-05 18:35:55.965776858 +0000
+++ m4/fp_find_cxx_std_lib.m4
@@ -26,7 +26,7 @@ unknown
 #endif
 EOF
         AC_MSG_CHECKING([C++ standard library flavour])
-        if ! "$CXX" -E actest.cpp -o actest.out; then
+        if ! $CXX -E actest.cpp -o actest.out; then
             rm -f actest.cpp actest.out
             AC_MSG_ERROR([Failed to compile test program])
         fi
@@ -54,16 +54,16 @@ int main(int argc, char** argv) {
     return 0;
 }
 EOF
-        if ! "$CXX" -c actest.cpp; then
+        if ! $CXX -c actest.cpp; then
             AC_MSG_ERROR([Failed to compile test object])
         fi
 
         try_libs() {
             dnl Try to link a plain object with CC manually
             AC_MSG_CHECKING([for linkage against '${3}'])
-            if "$CC" -o actest actest.o ${1} 2>/dev/null; then
+            if $CC -o actest actest.o ${1} 2>/dev/null; then
                 CXX_STD_LIB_LIBS="${3}"
-                p="`"$CXX" --print-file-name ${2}`"
+                p="`$CXX --print-file-name ${2}`"
                 d="`dirname "$p"`"
                 dnl On some platforms (e.g. Windows) the C++ standard library
                 dnl can be found in the system search path. In this case $CXX
