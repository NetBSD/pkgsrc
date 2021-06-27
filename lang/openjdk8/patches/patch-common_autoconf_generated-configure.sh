$NetBSD: patch-common_autoconf_generated-configure.sh,v 1.21 2021/06/27 14:54:41 tnn Exp $

BOOT_JDK_VERSION part: pkg/51221 (Build error with OpenJDK8 and i386) and
pkg/53223.
Fix detection of GCC>=10.

--- common/autoconf/generated-configure.sh.orig	2021-05-14 21:52:06.000000000 +0000
+++ common/autoconf/generated-configure.sh
@@ -4191,7 +4191,7 @@ VALID_TOOLCHAINS_all="gcc clang solstudi
 # These toolchains are valid on different platforms
 VALID_TOOLCHAINS_bsd="clang gcc"
 VALID_TOOLCHAINS_linux="gcc clang"
-VALID_TOOLCHAINS_solaris="solstudio"
+VALID_TOOLCHAINS_solaris="gcc solstudio"
 VALID_TOOLCHAINS_macosx="gcc clang"
 VALID_TOOLCHAINS_aix="xlc"
 VALID_TOOLCHAINS_windows="microsoft"
@@ -15482,9 +15482,6 @@ done
   # We need to find a recent version of GNU make. Especially on Solaris, this can be tricky.
   if test "x$MAKE" != x; then
     # User has supplied a make, test it.
-    if test ! -f "$MAKE"; then
-      as_fn_error $? "The specified make (by MAKE=$MAKE) is not found." "$LINENO" 5
-    fi
 
   MAKE_CANDIDATE=""$MAKE""
   DESCRIPTION="user supplied MAKE=$MAKE"
@@ -20173,7 +20170,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -20505,7 +20502,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -20823,7 +20820,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21011,7 +21008,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21289,7 +21286,7 @@ fi
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -21339,7 +21336,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21554,7 +21551,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21734,7 +21731,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -21942,7 +21939,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22122,7 +22119,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22330,7 +22327,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22510,7 +22507,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22718,7 +22715,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -22898,7 +22895,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23093,7 +23090,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23271,7 +23268,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23467,7 +23464,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23645,7 +23642,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -23840,7 +23837,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24018,7 +24015,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24214,7 +24211,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24392,7 +24389,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24569,7 +24566,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -24975,16 +24972,15 @@ $as_echo_n "checking flags for boot jdk 
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
@@ -27518,7 +27514,7 @@ $as_echo_n "checking resolved symbolic l
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -27973,7 +27969,7 @@ $as_echo_n "checking for resolved symbol
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -29259,7 +29255,7 @@ $as_echo_n "checking resolved symbolic l
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -29714,7 +29710,7 @@ $as_echo_n "checking for resolved symbol
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -41431,6 +41427,12 @@ $as_echo "$ac_cv_c_bigendian" >&6; }
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
@@ -41482,7 +41484,9 @@ $as_echo "$ac_cv_c_bigendian" >&6; }
   if test "x$OPENJDK_TARGET_OS" = xsolaris; then
     CFLAGS_JDK="${CFLAGS_JDK} -D__solaris__"
     CXXFLAGS_JDK="${CXXFLAGS_JDK} -D__solaris__"
+    if test "x$TOOLCHAIN_TYPE" = xsolstudio; then
     CFLAGS_JDKLIB_EXTRA='-xstrconst'
+    fi
   fi
   # The (cross) compiler is now configured, we can now test capabilities
   # of the target platform.
@@ -41623,7 +41627,7 @@ $as_echo "$ac_cv_c_bigendian" >&6; }
   elif test "x$TOOLCHAIN_TYPE" = xgcc; then
     LEGACY_EXTRA_CFLAGS="$LEGACY_EXTRA_CFLAGS -fstack-protector"
     LEGACY_EXTRA_CXXFLAGS="$LEGACY_EXTRA_CXXFLAGS -fstack-protector"
-    if test "x$OPENJDK_TARGET_OS" != xmacosx; then
+    if test "x$OPENJDK_TARGET_OS" != xmacosx -a test "x$OPENJDK_TARGET_OS" != xsolaris; then
       LDFLAGS_JDK="$LDFLAGS_JDK -Wl,-z,relro"
       LEGACY_EXTRA_LDFLAGS="$LEGACY_EXTRA_LDFLAGS -Wl,-z,relro"
     fi
@@ -42370,7 +42374,9 @@ $as_echo "$supports" >&6; }
       # Enabling pie on 32 bit builds prevents the JVM from allocating a continuous
       # java heap.
       if test "x$OPENJDK_TARGET_CPU_BITS" != "x32"; then
+       if test "x$OPENJDK_TARGET_OS" != "xsolaris"; then
         LDFLAGS_JDKEXE="$LDFLAGS_JDKEXE -pie"
+       fi
       fi
     fi
   fi
@@ -42863,7 +42869,8 @@ $as_echo "alsa pulse x11" >&6; }
   if test "x$OPENJDK_TARGET_OS" = xbsd; then
     { $as_echo "$as_me:${as_lineno-$LINENO}: checking what is not needed on BSD?" >&5
 $as_echo_n "checking what is not needed on BSD?... " >&6; }
-    if test "x$OPENJDK_TARGET_OS_VENDOR" = xopenbsd; then
+    if test "x$OPENJDK_TARGET_OS_VENDOR" = xopenbsd -o "x$OPENJDK_TARGET_OS_VENDOR" = xnetbsd -o "x$OPENJDK_TARGET_OS_VENDOR" = xfreebsd; then
+# XXX revisit this
       ALSA_NOT_NEEDED=yes
       PULSE_NOT_NEEDED=yes
       { $as_echo "$as_me:${as_lineno-$LINENO}: result: alsa pulse" >&5
@@ -44093,7 +44100,7 @@ $as_echo "$as_me: WARNING: Can't find pr
     BUILD_FREETYPE=no
   fi
   # Now check if configure found a version of 'msbuild.exe'
-  if test "x$BUILD_FREETYPE" = xyes && test "x$MSBUILD" == x ; then
+  if test "x$BUILD_FREETYPE" = xyes && test "x$MSBUILD" = x ; then
     { $as_echo "$as_me:${as_lineno-$LINENO}: WARNING: Can't find an msbuild.exe executable (you may try to install .NET 4.0) - ignoring --with-freetype-src" >&5
 $as_echo "$as_me: WARNING: Can't find an msbuild.exe executable (you may try to install .NET 4.0) - ignoring --with-freetype-src" >&2;}
     BUILD_FREETYPE=no
@@ -44509,7 +44516,11 @@ $as_echo "$as_me: WARNING: --with-freety
 
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
@@ -47619,7 +47630,7 @@ $as_echo "$as_me: The path of FREETYPE_I
     FREETYPE_INCLUDE_PATH="`cd "$path"; $THEPWDCMD -L`"
   fi
 
-      if test -d $FREETYPE_INCLUDE_PATH/freetype2/freetype; then
+      if test -d $FREETYPE_INCLUDE_PATH/freetype2; then
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH/freetype2 -I$FREETYPE_INCLUDE_PATH"
       else
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH"
@@ -47752,7 +47763,7 @@ $as_echo "$as_me: The path of FREETYPE_L
       if test "x$OPENJDK_TARGET_OS" = xwindows; then
         FREETYPE_LIBS="$FREETYPE_LIB_PATH/freetype.lib"
       else
-        FREETYPE_LIBS="-L$FREETYPE_LIB_PATH -lfreetype"
+        FREETYPE_LIBS="-Xlinker -R$FREETYPE_LIB_PATH -L$FREETYPE_LIB_PATH -lfreetype"
       fi
     fi
 
@@ -49089,9 +49100,6 @@ fi
 
 
 
-    if test "x$LLVM_CONFIG" != xllvm-config; then
-      as_fn_error $? "llvm-config not found in $PATH." "$LINENO" 5
-    fi
 
     llvm_components="jit mcjit engine nativecodegen native"
     unset LLVM_CFLAGS
@@ -49134,7 +49142,7 @@ fi
   fi
 
   # libCrun is the c++ runtime-library with SunStudio (roughly the equivalent of gcc's libstdc++.so)
-  if test "x$TOOLCHAIN_TYPE" = xsolstudio && test "x$LIBCXX" = x; then
+  if test "x$OPENJDK_TARGET_OS" = xsolaris && test "x$LIBCXX" = x && test "x$GCC" = "xno"; then
     LIBCXX="${SYSROOT}/usr/lib${OPENJDK_TARGET_CPU_ISADIR}/libCrun.so.1"
   fi
 
