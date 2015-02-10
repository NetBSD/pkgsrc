$NetBSD: patch-common_autoconf_generated-configure.sh,v 1.2 2015/02/10 08:20:27 tnn Exp $

--- common/autoconf/generated-configure.sh.orig	2015-02-02 15:31:06.000000000 +0000
+++ common/autoconf/generated-configure.sh
@@ -8379,9 +8379,9 @@ done
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
@@ -12483,7 +12483,7 @@ fi
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -19643,7 +19643,7 @@ $as_echo_n "checking resolved symbolic l
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -20081,7 +20081,7 @@ $as_echo_n "checking for resolved symbol
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -21244,7 +21244,7 @@ $as_echo_n "checking resolved symbolic l
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -21682,7 +21682,7 @@ $as_echo_n "checking for resolved symbol
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -29731,7 +29731,7 @@ fi
   #
   case $COMPILER_NAME in
     gcc )
-      CCXXFLAGS_JDK="$CCXXFLAGS $CCXXFLAGS_JDK -W -Wall -Wno-unused -Wno-parentheses \
+      CCXXFLAGS_JDK="$CCXXFLAGS $CCXXFLAGS_JDK -W -Wall -Wno-unused -Wno-unused-parameter -Wno-parentheses \
       -pipe \
       -D_GNU_SOURCE -D_REENTRANT -D_LARGEFILE64_SOURCE"
       case $OPENJDK_TARGET_CPU_ARCH in
@@ -30345,6 +30345,8 @@ $as_echo "alsa pulse x11" >&6; }
     { $as_echo "$as_me:${as_lineno-$LINENO}: checking what is not needed on BSD?" >&5
 $as_echo_n "checking what is not needed on BSD?... " >&6; }
     PULSE_NOT_NEEDED=yes
+# disable sound for now. XXX revisit this.
+    ALSA_NOT_NEEDED=yes
     { $as_echo "$as_me:${as_lineno-$LINENO}: result: pulse" >&5
 $as_echo "pulse" >&6; }
   fi
@@ -31555,7 +31557,11 @@ $as_echo "$as_me: WARNING: freetype not 
 
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
@@ -34373,7 +34379,7 @@ $as_echo "$as_me: The path of FREETYPE_I
     FREETYPE_INCLUDE_PATH="`cd "$path"; $THEPWDCMD -L`"
   fi
 
-      if test -d $FREETYPE_INCLUDE_PATH/freetype2/freetype; then
+      if test -d $FREETYPE_INCLUDE_PATH/freetype2; then
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH/freetype2 -I$FREETYPE_INCLUDE_PATH"
       else
         FREETYPE_CFLAGS="-I$FREETYPE_INCLUDE_PATH"
@@ -34506,7 +34512,7 @@ $as_echo "$as_me: The path of FREETYPE_L
       if test "x$OPENJDK_TARGET_OS" = xwindows; then
         FREETYPE_LIBS="$FREETYPE_LIB_PATH/freetype.lib"
       else
-        FREETYPE_LIBS="-L$FREETYPE_LIB_PATH -lfreetype"
+        FREETYPE_LIBS="-Xlinker -R$FREETYPE_LIB_PATH -L$FREETYPE_LIB_PATH -lfreetype"
       fi
     fi
 
