$NetBSD: patch-common_autoconf_generated-configure.sh,v 1.28 2026/02/01 06:50:58 ryoon Exp $

Various fixes.

--- common/autoconf/generated-configure.sh.orig	2026-01-23 00:36:25.000000000 +0000
+++ common/autoconf/generated-configure.sh
@@ -4176,7 +4176,7 @@ VALID_TOOLCHAINS_linux="gcc clang"
 # These toolchains are valid on different platforms
 VALID_TOOLCHAINS_bsd="clang gcc"
 VALID_TOOLCHAINS_linux="gcc clang"
-VALID_TOOLCHAINS_solaris="solstudio"
+VALID_TOOLCHAINS_solaris="gcc solstudio"
 VALID_TOOLCHAINS_macosx="gcc clang"
 VALID_TOOLCHAINS_aix="xlc"
 VALID_TOOLCHAINS_windows="microsoft"
@@ -15732,9 +15732,6 @@ done
   # We need to find a recent version of GNU make. Especially on Solaris, this can be tricky.
   if test "x$MAKE" != x; then
     # User has supplied a make, test it.
-    if test ! -f "$MAKE"; then
-      as_fn_error $? "The specified make (by MAKE=$MAKE) is not found." "$LINENO" 5
-    fi
 
   MAKE_CANDIDATE=""$MAKE""
   DESCRIPTION="user supplied MAKE=$MAKE"
@@ -20609,7 +20606,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -20952,7 +20949,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21292,7 +21289,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version` 
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21491,7 +21488,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21780,7 +21777,7 @@ fi
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -21830,7 +21827,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22056,7 +22053,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22247,7 +22244,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22466,7 +22463,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22657,7 +22654,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22876,7 +22873,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23067,7 +23064,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23286,7 +23283,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23477,7 +23474,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23683,7 +23680,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23872,7 +23869,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24079,7 +24076,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24268,7 +24265,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24474,7 +24471,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24663,7 +24660,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24870,7 +24867,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -25059,7 +25056,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -25247,7 +25244,7 @@ $as_echo "$as_me: Potential Boot JDK found at $BOOT_JD
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -25664,16 +25661,15 @@ $as_echo_n "checking flags for boot jdk java command f
   # Maximum amount of heap memory.
   # Maximum stack size.
   if test "x$BOOT_JDK_BITS" = x32; then
-    JVM_MAX_HEAP=768M
     STACK_SIZE=768
   else
     # Running Javac on a JVM on a 64-bit machine, takes more space since 64-bit
     # pointers are used. Apparently, we need to increase the heap and stack
     # space for the jvm. More specifically, when running javac to build huge
     # jdk batch
-    JVM_MAX_HEAP=1600M
     STACK_SIZE=1536
   fi
+  JVM_MAX_HEAP=800M
 
   $ECHO "Check if jvm arg is ok: -Xmx$JVM_MAX_HEAP" >&5
   $ECHO "Command: $JAVA -Xmx$JVM_MAX_HEAP -version" >&5
@@ -28224,7 +28220,7 @@ $as_echo_n "checking resolved symbolic links for CC...
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -28679,7 +28675,7 @@ $as_echo_n "checking for resolved symbolic links for C
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -29963,7 +29959,7 @@ $as_echo_n "checking resolved symbolic links for CXX..
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -30418,7 +30414,7 @@ $as_echo_n "checking for resolved symbolic links for C
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -42567,6 +42563,12 @@ $as_echo "$ac_cv_c_bigendian" >&6; }
       SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
       SET_SHARED_LIBRARY_NAME='-Xlinker -install_name -Xlinker @rpath/$1'
       SET_SHARED_LIBRARY_MAPFILE=''
+    elif test "x$OPENJDK_TARGET_OS" = xsolaris; then
+      SHARED_LIBRARY_FLAGS="-shared"
+      SET_EXECUTABLE_ORIGIN='-R\$$$$ORIGIN$1'
+      SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
+      SET_SHARED_LIBRARY_NAME=''
+      SET_SHARED_LIBRARY_MAPFILE=''
     else
       # Default works for linux, might work on other platforms as well.
       SHARED_LIBRARY_FLAGS='-shared'
@@ -42638,7 +42640,9 @@ $as_echo "$ac_cv_c_bigendian" >&6; }
   if test "x$OPENJDK_TARGET_OS" = xsolaris; then
     CFLAGS_JDK="${CFLAGS_JDK} -D__solaris__"
     CXXFLAGS_JDK="${CXXFLAGS_JDK} -D__solaris__"
-    CFLAGS_JDKLIB_EXTRA='-xstrconst'
+    if test "x$TOOLCHAIN_TYPE" = xsolstudio; then
+      CFLAGS_JDKLIB_EXTRA='-xstrconst'
+    fi
   fi
   # The (cross) compiler is now configured, we can now test capabilities
   # of the target platform.
@@ -42800,7 +42804,7 @@ $as_echo "$ac_cv_c_bigendian" >&6; }
     LEGACY_TARGET_CFLAGS="$LEGACY_TARGET_CFLAGS -fstack-protector"
     LEGACY_HOST_CXXFLAGS="$LEGACY_HOST_CXXFLAGS -fstack-protector"
     LEGACY_TARGET_CXXFLAGS="$LEGACY_TARGET_CXXFLAGS -fstack-protector"
-    if test "x$OPENJDK_TARGET_OS" != xmacosx; then
+    if test "x$OPENJDK_TARGET_OS" != xmacosx -a test "x$OPENJDK_TARGET_OS" != xsolaris; then
       LDFLAGS_JDK="$LDFLAGS_JDK -Wl,-z,relro"
       LEGACY_HOST_LDFLAGS="$LEGACY_HOST_LDFLAGS -Wl,-z,relro"
       LEGACY_TARGET_LDFLAGS="$LEGACY_TARGET_LDFLAGS -Wl,-z,relro"
@@ -42851,7 +42855,7 @@ $as_echo "$supports" >&6; }
   elif test "x$TOOLCHAIN_TYPE" = xclang; then
     LEGACY_EXTRA_CFLAGS="$LEGACY_EXTRA_CFLAGS -fstack-protector"
     LEGACY_EXTRA_CXXFLAGS="$LEGACY_EXTRA_CXXFLAGS -fstack-protector"
-    if test "x$OPENJDK_TARGET_OS" != xmacosx; then
+    if test "x$OPENJDK_TARGET_OS" != xmacosx -a test "x$OPENJDK_TARGET_OS" != xsolaris; then
       LDFLAGS_JDK="$LDFLAGS_JDK -Wl,-z,relro"
       LEGACY_EXTRA_LDFLAGS="$LEGACY_EXTRA_LDFLAGS -Wl,-z,relro"
     fi
@@ -43697,7 +43701,9 @@ $as_echo "$supports" >&6; }
       # Enabling pie on 32 bit builds prevents the JVM from allocating a continuous
       # java heap.
       if test "x$OPENJDK_TARGET_CPU_BITS" != "x32"; then
-        LDFLAGS_JDKEXE="$LDFLAGS_JDKEXE -pie"
+        if test "x$OPENJDK_TARGET_OS" != "xsolaris"; then
+          LDFLAGS_JDKEXE="$LDFLAGS_JDKEXE -pie"
+        fi
       fi
     fi
   fi
@@ -44185,7 +44191,8 @@ $as_echo_n "checking what is not needed on BSD?... " >
   if test "x$OPENJDK_TARGET_OS" = xbsd; then
     { $as_echo "$as_me:${as_lineno-$LINENO}: checking what is not needed on BSD?" >&5
 $as_echo_n "checking what is not needed on BSD?... " >&6; }
-    if test "x$OPENJDK_TARGET_OS_VENDOR" = xopenbsd; then
+    if test "x$OPENJDK_TARGET_OS_VENDOR" = xopenbsd -o "x$OPENJDK_TARGET_OS_VENDOR" = xnetbsd -o "x$OPENJDK_TARGET_OS_VENDOR" = xfreebsd; then
+# XXX revisit this
       ALSA_NOT_NEEDED=yes
       PULSE_NOT_NEEDED=yes
       { $as_echo "$as_me:${as_lineno-$LINENO}: result: alsa pulse" >&5
@@ -46022,7 +46029,7 @@ $as_echo "$FREETYPE_LIB_PATH" >&6; }
 
     # Set FREETYPE_CFLAGS, _LIBS and _LIB_PATH from include and lib dir.
     if test "x$FREETYPE_CFLAGS" = "x" ; then
-      if test -d $FREETYPE_INCLUDE_PATH/freetype2/freetype ; then
+      if test -d $FREETYPE_INCLUDE_PATH/freetype2 ; then
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH/freetype2 -I$FREETYPE_INCLUDE_PATH"
       else
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH"
@@ -46030,7 +46037,7 @@ $as_echo "$FREETYPE_LIB_PATH" >&6; }
     fi
 
     if test "x$FREETYPE_LIBS" = "x" ; then
-      FREETYPE_LIBS="-L$FREETYPE_LIB_PATH -l$FREETYPE_BASE_NAME"
+      FREETYPE_LIBS="-Xlinker -R$FREETYPE_LIB_PATH -L$FREETYPE_LIB_PATH -l$FREETYPE_BASE_NAME"
     fi
   fi
 
@@ -47273,9 +47280,6 @@ fi
 
 
 
-    if test "x$LLVM_CONFIG" != xllvm-config; then
-      as_fn_error $? "llvm-config not found in $PATH." "$LINENO" 5
-    fi
 
     llvm_components="jit mcjit engine nativecodegen native"
     unset LLVM_CFLAGS
@@ -47318,7 +47322,7 @@ fi
   fi
 
   # libCrun is the c++ runtime-library with SunStudio (roughly the equivalent of gcc's libstdc++.so)
-  if test "x$TOOLCHAIN_TYPE" = xsolstudio && test "x$LIBCXX" = x; then
+  if test "x$OPENJDK_TARGET_OS" = xsolaris && test "x$LIBCXX" = x && test "x$GCC" = "xno"; then
     LIBCXX="${SYSROOT}/usr/lib${OPENJDK_TARGET_CPU_ISADIR}/libCrun.so.1"
   fi
 
@@ -52302,7 +52306,7 @@ $as_echo_n "checking for memory size... " >&6; }
     FOUND_MEM=yes
   elif test "x$OPENJDK_BUILD_OS" = xbsd && test "x$(uname -s | grep -o BSD)" = xBSD; then
     # Looks like a BSD system
-    MEMORY_SIZE=`/sbin/sysctl -n hw.physmem`
+    MEMORY_SIZE=`/sbin/sysctl -n hw.physmem64 || /sbin/sysctl -n hw.physmem`
     MEMORY_SIZE=`expr $MEMORY_SIZE / 1024 / 1024`
     FOUND_MEM=yes
   elif test "x$OPENJDK_BUILD_OS" = xwindows; then
