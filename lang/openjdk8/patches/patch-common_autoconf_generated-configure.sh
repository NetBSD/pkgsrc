$NetBSD: patch-common_autoconf_generated-configure.sh,v 1.4 2015/06/10 11:38:51 tnn Exp $

--- common/autoconf/generated-configure.sh.orig	2015-06-09 13:44:54.000000000 +0000
+++ common/autoconf/generated-configure.sh
@@ -6883,7 +6883,7 @@ test -n "$target_alias" &&
       VAR_CPU_BITS=32
       VAR_CPU_ENDIAN=big
       ;;
-    sparcv9)
+    sparcv9|sparc64)
       VAR_CPU=sparcv9
       VAR_CPU_ARCH=sparc
       VAR_CPU_BITS=64
@@ -7030,7 +7030,7 @@ $as_echo "$OPENJDK_BUILD_OS-$OPENJDK_BUI
       VAR_CPU_BITS=32
       VAR_CPU_ENDIAN=big
       ;;
-    sparcv9)
+    sparcv9|sparc64)
       VAR_CPU=sparcv9
       VAR_CPU_ARCH=sparc
       VAR_CPU_BITS=64
@@ -8421,9 +8421,9 @@ done
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
@@ -12543,7 +12543,7 @@ fi
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -19774,7 +19774,7 @@ $as_echo_n "checking resolved symbolic l
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -20212,7 +20212,7 @@ $as_echo_n "checking for resolved symbol
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -21375,7 +21375,7 @@ $as_echo_n "checking resolved symbolic l
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -21813,7 +21813,7 @@ $as_echo_n "checking for resolved symbol
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -29862,7 +29862,7 @@ fi
   #
   case $COMPILER_NAME in
     gcc )
-      CCXXFLAGS_JDK="$CCXXFLAGS $CCXXFLAGS_JDK -W -Wall -Wno-unused -Wno-parentheses \
+      CCXXFLAGS_JDK="$CCXXFLAGS $CCXXFLAGS_JDK -W -Wall -Wno-unused -Wno-unused-parameter -Wno-parentheses \
       -pipe \
       -D_GNU_SOURCE -D_REENTRANT -D_LARGEFILE64_SOURCE"
       case $OPENJDK_TARGET_CPU_ARCH in
@@ -30475,7 +30475,8 @@ $as_echo "alsa pulse x11" >&6; }
   if test "x$OPENJDK_TARGET_OS" = xbsd; then
     { $as_echo "$as_me:${as_lineno-$LINENO}: checking what is not needed on BSD?" >&5
 $as_echo_n "checking what is not needed on BSD?... " >&6; }
-    if test "x$OPENJDK_TARGET_OS_VENDOR" = xopenbsd; then
+    if test "x$OPENJDK_TARGET_OS_VENDOR" = xopenbsd -o "x$OPENJDK_TARGET_OS_VENDOR" = xnetbsd; then
+# XXX revisit this
       ALSA_NOT_NEEDED=yes
       PULSE_NOT_NEEDED=yes
       { $as_echo "$as_me:${as_lineno-$LINENO}: result: alsa pulse" >&5
@@ -31701,7 +31702,11 @@ $as_echo "$as_me: WARNING: freetype not 
 
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
@@ -34519,7 +34524,7 @@ $as_echo "$as_me: The path of FREETYPE_I
     FREETYPE_INCLUDE_PATH="`cd "$path"; $THEPWDCMD -L`"
   fi
 
-      if test -d $FREETYPE_INCLUDE_PATH/freetype2/freetype; then
+      if test -d $FREETYPE_INCLUDE_PATH/freetype2; then
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH/freetype2 -I$FREETYPE_INCLUDE_PATH"
       else
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH"
@@ -34652,7 +34657,7 @@ $as_echo "$as_me: The path of FREETYPE_L
       if test "x$OPENJDK_TARGET_OS" = xwindows; then
         FREETYPE_LIBS="$FREETYPE_LIB_PATH/freetype.lib"
       else
-        FREETYPE_LIBS="-L$FREETYPE_LIB_PATH -lfreetype"
+        FREETYPE_LIBS="-Xlinker -R$FREETYPE_LIB_PATH -L$FREETYPE_LIB_PATH -lfreetype"
       fi
     fi
 
