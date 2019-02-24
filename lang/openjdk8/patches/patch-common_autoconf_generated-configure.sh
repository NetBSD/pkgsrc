$NetBSD: patch-common_autoconf_generated-configure.sh,v 1.17 2019/02/24 16:43:28 jperkin Exp $

BOOT_JDK_VERSION part: pkg/51221 (Build error with OpenJDK8 and i386) and
pkg/53223.

--- common/autoconf/generated-configure.sh.orig	2019-02-19 13:34:21.000000000 +0000
+++ common/autoconf/generated-configure.sh
@@ -4137,7 +4137,7 @@ VALID_TOOLCHAINS_all="gcc clang solstudi
 # These toolchains are valid on different platforms
 VALID_TOOLCHAINS_bsd="clang gcc"
 VALID_TOOLCHAINS_linux="gcc clang"
-VALID_TOOLCHAINS_solaris="solstudio"
+VALID_TOOLCHAINS_solaris="gcc solstudio"
 VALID_TOOLCHAINS_macosx="gcc clang"
 VALID_TOOLCHAINS_aix="xlc"
 VALID_TOOLCHAINS_windows="microsoft"
@@ -15416,9 +15416,6 @@ done
   # We need to find a recent version of GNU make. Especially on Solaris, this can be tricky.
   if test "x$MAKE" != x; then
     # User has supplied a make, test it.
-    if test ! -f "$MAKE"; then
-      as_fn_error $? "The specified make (by MAKE=$MAKE) is not found." "$LINENO" 5
-    fi
 
   MAKE_CANDIDATE=""$MAKE""
   DESCRIPTION="user supplied MAKE=$MAKE"
@@ -20006,7 +20003,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -20338,7 +20335,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -20656,7 +20653,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -20844,7 +20841,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21122,7 +21119,7 @@ fi
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -21172,7 +21169,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21387,7 +21384,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21567,7 +21564,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21775,7 +21772,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21955,7 +21952,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22163,7 +22160,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22343,7 +22340,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22551,7 +22548,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22731,7 +22728,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22926,7 +22923,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23104,7 +23101,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23300,7 +23297,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23478,7 +23475,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23673,7 +23670,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23851,7 +23848,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24047,7 +24044,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24225,7 +24222,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24402,7 +24399,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24808,16 +24805,15 @@ $as_echo_n "checking flags for boot jdk
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
@@ -27351,7 +27347,7 @@ $as_echo_n "checking resolved symbolic l
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -27806,7 +27802,7 @@ $as_echo_n "checking for resolved symbol
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -29092,7 +29088,7 @@ $as_echo_n "checking resolved symbolic l
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -29547,7 +29543,7 @@ $as_echo_n "checking for resolved symbol
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -41263,6 +41259,12 @@ $as_echo "$ac_cv_c_bigendian" >&6; }
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
@@ -41311,7 +41313,9 @@ $as_echo "$ac_cv_c_bigendian" >&6; }
   if test "x$OPENJDK_TARGET_OS" = xsolaris; then
     CFLAGS_JDK="${CFLAGS_JDK} -D__solaris__"
     CXXFLAGS_JDK="${CXXFLAGS_JDK} -D__solaris__"
+    if test "x$TOOLCHAIN_TYPE" = xsolstudio; then
     CFLAGS_JDKLIB_EXTRA='-xstrconst'
+    fi
   fi
   # The (cross) compiler is now configured, we can now test capabilities
   # of the target platform.
@@ -41460,7 +41464,7 @@ $as_echo "$ac_cv_c_bigendian" >&6; }
       LEGACY_EXTRA_CXXFLAGS="$LEGACY_EXTRA_CXXFLAGS -fstack-protector"
       ;;
     esac
-    if test "x$OPENJDK_TARGET_OS" != xmacosx; then
+    if test "x$OPENJDK_TARGET_OS" != xmacosx -a test "x$OPENJDK_TARGET_OS" != xsolaris; then
       LDFLAGS_JDK="$LDFLAGS_JDK -Wl,-z,relro"
       LEGACY_EXTRA_LDFLAGS="$LEGACY_EXTRA_LDFLAGS -Wl,-z,relro"
     fi
@@ -42536,7 +42540,8 @@ $as_echo "alsa pulse x11" >&6; }
   if test "x$OPENJDK_TARGET_OS" = xbsd; then
     { $as_echo "$as_me:${as_lineno-$LINENO}: checking what is not needed on BSD?" >&5
 $as_echo_n "checking what is not needed on BSD?... " >&6; }
-    if test "x$OPENJDK_TARGET_OS_VENDOR" = xopenbsd; then
+    if test "x$OPENJDK_TARGET_OS_VENDOR" = xopenbsd -o "x$OPENJDK_TARGET_OS_VENDOR" = xnetbsd -o "x$OPENJDK_TARGET_OS_VENDOR" = xfreebsd; then
+# XXX revisit this
       ALSA_NOT_NEEDED=yes
       PULSE_NOT_NEEDED=yes
       { $as_echo "$as_me:${as_lineno-$LINENO}: result: alsa pulse" >&5
@@ -43766,7 +43771,7 @@ $as_echo "$as_me: WARNING: Can't find pr
     BUILD_FREETYPE=no
   fi
   # Now check if configure found a version of 'msbuild.exe'
-  if test "x$BUILD_FREETYPE" = xyes && test "x$MSBUILD" == x ; then
+  if test "x$BUILD_FREETYPE" = xyes && test "x$MSBUILD" = x ; then
     { $as_echo "$as_me:${as_lineno-$LINENO}: WARNING: Can't find an msbuild.exe executable (you may try to install .NET 4.0) - ignoring --with-freetype-src" >&5
 $as_echo "$as_me: WARNING: Can't find an msbuild.exe executable (you may try to install .NET 4.0) - ignoring --with-freetype-src" >&2;}
     BUILD_FREETYPE=no
@@ -44182,7 +44187,11 @@ $as_echo "$as_me: WARNING: --with-freety
 
       # Allow --with-freetype-lib and --with-freetype-include to override
       if test "x$with_freetype_include" != x; then
-        POTENTIAL_FREETYPE_INCLUDE_PATH="$with_freetype_include"
+          POTENTIAL_FREETYPE_INCLUDE_PATH="$with_freetype_include"
+           # deal w/ freetype2 in new location
+          if test -f "$with_freetype_include"/freetype2/ft2build.h; then
+            POTENTIAL_FREETYPE_INCLUDE_PATH="$with_freetype_include"/freetype2
+          fi
       fi
       if test "x$with_freetype_lib" != x; then
         POTENTIAL_FREETYPE_LIB_PATH="$with_freetype_lib"
@@ -47292,7 +47301,7 @@ $as_echo "$as_me: The path of FREETYPE_I
     FREETYPE_INCLUDE_PATH="`cd "$path"; $THEPWDCMD -L`"
   fi
 
-      if test -d $FREETYPE_INCLUDE_PATH/freetype2/freetype; then
+      if test -d $FREETYPE_INCLUDE_PATH/freetype2; then
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH/freetype2 -I$FREETYPE_INCLUDE_PATH"
       else
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH"
@@ -47425,7 +47434,7 @@ $as_echo "$as_me: The path of FREETYPE_L
       if test "x$OPENJDK_TARGET_OS" = xwindows; then
         FREETYPE_LIBS="$FREETYPE_LIB_PATH/freetype.lib"
       else
-        FREETYPE_LIBS="-L$FREETYPE_LIB_PATH -lfreetype"
+        FREETYPE_LIBS="-Xlinker -R$FREETYPE_LIB_PATH -L$FREETYPE_LIB_PATH -lfreetype"
       fi
     fi
 
@@ -48654,9 +48663,6 @@ fi
 
 
 
-    if test "x$LLVM_CONFIG" != xllvm-config; then
-      as_fn_error $? "llvm-config not found in $PATH." "$LINENO" 5
-    fi
 
     llvm_components="jit mcjit engine nativecodegen native"
     unset LLVM_CFLAGS
@@ -48699,7 +48705,7 @@ fi
   fi
 
   # libCrun is the c++ runtime-library with SunStudio (roughly the equivalent of gcc's libstdc++.so)
-  if test "x$TOOLCHAIN_TYPE" = xsolstudio && test "x$LIBCXX" = x; then
+  if test "x$OPENJDK_TARGET_OS" = xsolaris && test "x$LIBCXX" = x && test "x$GCC" = "xno"; then
     LIBCXX="${SYSROOT}/usr/lib${OPENJDK_TARGET_CPU_ISADIR}/libCrun.so.1"
   fi
 
