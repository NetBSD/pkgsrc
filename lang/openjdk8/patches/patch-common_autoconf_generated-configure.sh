$NetBSD: patch-common_autoconf_generated-configure.sh,v 1.11.4.1 2017/05/18 19:02:33 bsiegert Exp $

BOOT_JDK_VERSION part: pkg/51221 (Build error with OpenJDK8 and i386)

--- common/autoconf/generated-configure.sh.orig	2016-10-26 22:56:42.000000000 +0000
+++ common/autoconf/generated-configure.sh
@@ -8454,9 +8454,9 @@ done
   # We need to find a recent version of GNU make. Especially on Solaris, this can be tricky.
   if test "x$MAKE" != x; then
     # User has supplied a make, test it.
-    if test ! -f "$MAKE"; then
-      as_fn_error $? "The specified make (by MAKE=$MAKE) is not found." "$LINENO" 5
-    fi
+#    if test ! -f "$MAKE"; then
+#      as_fn_error $? "The specified make (by MAKE=$MAKE) is not found." "$LINENO" 5
+#    fi
 
   MAKE_CANDIDATE=""$MAKE""
   DESCRIPTION="user supplied MAKE=$MAKE"
@@ -11755,7 +11755,7 @@ $as_echo "$as_me: Potential Boot JDK fou
             BOOT_JDK_FOUND=no
           else
             # Oh, this is looking good! We probably have found a proper JDK. Is it the correct version?
-            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | head -n 1`
+            BOOT_JDK_VERSION=`"$BOOT_JDK/bin/java" -version 2>&1 | grep version`
 
             # Extra M4 quote needed to protect [] in grep expression.
             FOUND_VERSION_78=`echo $BOOT_JDK_VERSION | grep  '\"1\.[78]\.'`
@@ -12539,7 +12539,7 @@ fi
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -16225,16 +16225,15 @@ $as_echo_n "checking flags for boot jdk 
   # Maximum amount of heap memory.
   # Maximum stack size.
   if test "x$BOOT_JDK_BITS" = x32; then
-    JVM_MAX_HEAP=1100M
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
@@ -19454,7 +19453,7 @@ $as_echo "(none, will use system headers
   elif test "x$OPENJDK_TARGET_OS" = "xwindows"; then
     COMPILER_CHECK_LIST="cl"
   elif test "x$OPENJDK_TARGET_OS" = "xsolaris"; then
-    COMPILER_CHECK_LIST="cc gcc"
+    COMPILER_CHECK_LIST="gcc cc"
   elif test "x$OPENJDK_TARGET_OS" = "xaix"; then
     # Do not probe for cc on AIX.
     COMPILER_CHECK_LIST="xlc_r"
@@ -19910,7 +19909,7 @@ $as_echo_n "checking resolved symbolic l
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -20348,7 +20347,7 @@ $as_echo_n "checking for resolved symbol
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -20376,7 +20375,7 @@ $as_echo "no, keeping CC" >&6; }
   COMPILER=$CC
   COMPILER_NAME=$COMPILER_NAME
 
-  if test "x$OPENJDK_TARGET_OS" = xsolaris; then
+  if test "x$OPENJDK_TARGET_OS" = xsolaris && test "x$GCC" = xno; then
     # Make sure we use the Sun Studio compiler and not gcc on Solaris, which won't work
     COMPILER_VERSION_TEST=`$COMPILER -V 2>&1 | $HEAD -n 1`
     $ECHO $COMPILER_VERSION_TEST | $GREP "^.*: Sun $COMPILER_NAME" > /dev/null
@@ -21511,7 +21510,7 @@ $as_echo_n "checking resolved symbolic l
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -21949,7 +21948,7 @@ $as_echo_n "checking for resolved symbol
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -21977,7 +21976,7 @@ $as_echo "no, keeping CXX" >&6; }
   COMPILER=$CXX
   COMPILER_NAME=$COMPILER_NAME
 
-  if test "x$OPENJDK_TARGET_OS" = xsolaris; then
+  if test "x$OPENJDK_TARGET_OS" = xsolaris && test "x$GCC" = xno; then
     # Make sure we use the Sun Studio compiler and not gcc on Solaris, which won't work
     COMPILER_VERSION_TEST=`$COMPILER -V 2>&1 | $HEAD -n 1`
     $ECHO $COMPILER_VERSION_TEST | $GREP "^.*: Sun $COMPILER_NAME" > /dev/null
@@ -29390,6 +29389,15 @@ $as_echo "$ac_cv_c_bigendian" >&6; }
     if test "x$OPENJDK_TARGET_OS" = xbsd || test "x$OPENJDK_TARGET_OS" = xmacosx; then
       SET_EXECUTABLE_ORIGIN="$SET_SHARED_LIBRARY_ORIGIN"
     fi
+    if test "x$OPENJDK_TARGET_OS" = xsolaris; then
+      SET_SHARED_LIBRARY_NAME=''
+      SET_SHARED_LIBRARY_MAPFILE=''
+      SET_SHARED_LIBRARY_ORIGIN='-R\$$$$ORIGIN$1'
+      SET_EXECUTABLE_ORIGIN="$SET_SHARED_LIBRARY_ORIGIN"
+      CFLAGS_JDK="${CFLAGS_JDK} -D__solaris__"
+      CXXFLAGS_JDK="${CXXFLAGS_JDK} -D__solaris__"
+      POST_STRIP_CMD="$STRIP -x"
+    fi
   else
     if test "x$OPENJDK_TARGET_OS" = xsolaris; then
       # If it is not gcc, then assume it is the Oracle Solaris Studio Compiler
@@ -29531,6 +29539,13 @@ rm -f core conftest.err conftest.$ac_obj
               C_O_FLAG_NORM="-Os"
               C_O_FLAG_NONE=""
               ;;
+            solaris )
+              # libverify currently crashes in 32-bit builds with
+              # alignment faults, temporary workaround with -O2
+              C_O_FLAG_HI="-O2"
+              C_O_FLAG_NORM="-O2"
+              C_O_FLAG_NONE="-O0"
+              ;;
             *)
               C_O_FLAG_HI="-O3"
               C_O_FLAG_NORM="-O2"
@@ -29732,7 +29747,7 @@ fi
   #
   case $COMPILER_NAME in
     gcc )
-      CCXXFLAGS_JDK="$CCXXFLAGS $CCXXFLAGS_JDK -W -Wall -Wno-unused -Wno-parentheses -Wno-sign-compare \
+      CCXXFLAGS_JDK="$CCXXFLAGS $CCXXFLAGS_JDK -W -Wall -Wno-unused -Wno-parentheses -Wno-sign-compare -Wno-unused-parameter \
       -pipe \
       -D_GNU_SOURCE -D_REENTRANT -D_LARGEFILE64_SOURCE"
       case $OPENJDK_TARGET_CPU_ARCH in
@@ -30343,7 +30358,8 @@ $as_echo "alsa pulse x11" >&6; }
   if test "x$OPENJDK_TARGET_OS" = xbsd; then
     { $as_echo "$as_me:${as_lineno-$LINENO}: checking what is not needed on BSD?" >&5
 $as_echo_n "checking what is not needed on BSD?... " >&6; }
-    if test "x$OPENJDK_TARGET_OS_VENDOR" = xopenbsd; then
+    if test "x$OPENJDK_TARGET_OS_VENDOR" = xopenbsd -o "x$OPENJDK_TARGET_OS_VENDOR" = xnetbsd -o "x$OPENJDK_TARGET_OS_VENDOR" = xfreebsd; then
+# XXX revisit this
       ALSA_NOT_NEEDED=yes
       PULSE_NOT_NEEDED=yes
       { $as_echo "$as_me:${as_lineno-$LINENO}: result: alsa pulse" >&5
@@ -31555,7 +31571,11 @@ $as_echo "$as_me: WARNING: freetype not 
 
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
@@ -34373,7 +34393,7 @@ $as_echo "$as_me: The path of FREETYPE_I
     FREETYPE_INCLUDE_PATH="`cd "$path"; $THEPWDCMD -L`"
   fi
 
-      if test -d $FREETYPE_INCLUDE_PATH/freetype2/freetype; then
+      if test -d $FREETYPE_INCLUDE_PATH/freetype2; then
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH/freetype2 -I$FREETYPE_INCLUDE_PATH"
       else
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH"
@@ -34506,7 +34526,7 @@ $as_echo "$as_me: The path of FREETYPE_L
       if test "x$OPENJDK_TARGET_OS" = xwindows; then
         FREETYPE_LIBS="$FREETYPE_LIB_PATH/freetype.lib"
       else
-        FREETYPE_LIBS="-L$FREETYPE_LIB_PATH -lfreetype"
+        FREETYPE_LIBS="-Xlinker -R$FREETYPE_LIB_PATH -L$FREETYPE_LIB_PATH -lfreetype"
       fi
     fi
 
@@ -35732,9 +35752,6 @@ fi
 
 
 
-    if test "x$LLVM_CONFIG" != xllvm-config; then
-      as_fn_error $? "llvm-config not found in $PATH." "$LINENO" 5
-    fi
 
     llvm_components="jit mcjit engine nativecodegen native"
     unset LLVM_CFLAGS
@@ -35777,7 +35794,7 @@ fi
   fi
 
   # libCrun is the c++ runtime-library with SunStudio (roughly the equivalent of gcc's libstdc++.so)
-  if test "x$OPENJDK_TARGET_OS" = xsolaris && test "x$LIBCXX" = x; then
+  if test "x$OPENJDK_TARGET_OS" = xsolaris && test "x$LIBCXX" = x && test "x$GCC" = "xno"; then
     LIBCXX="/usr/lib${OPENJDK_TARGET_CPU_ISADIR}/libCrun.so.1"
   fi
 
