$NetBSD: patch-build-aux_ltmain.sh,v 1.4 2022/08/03 13:06:32 jperkin Exp $

Automatically generated using manual-* patches and bootstrap.
DO NOT MODIFY THIS PATCH MANUALLY!  YOUR CHANGES WILL BE LOST!

--- build-aux/ltmain.sh.orig	2022-08-03 12:14:26.878811652 +0000
+++ build-aux/ltmain.sh
@@ -323,6 +323,9 @@ test -z "$GREP" && {
 # uses them if a suitable command of that name is not already available
 # in the command search PATH.
 
+unset CP
+unset MV
+unset RM
 : ${CP="cp -f"}
 : ${ECHO="printf %s\n"}
 : ${EGREP="$GREP -E"}
@@ -2311,7 +2314,7 @@ include the following information:
        autoconf:       `($AUTOCONF --version) 2>/dev/null |$SED 1q`
 
 Report bugs to <bug-libtool@gnu.org>.
-GNU libtool home page: <http://www.gnu.org/software/libtool/>.
+GNU libtool home page: <http://www.gnu.org/s/libtool/>.
 General help using GNU software: <http://www.gnu.org/gethelp/>."
     exit 0
 }
@@ -8628,7 +8631,11 @@ func_mode_link ()
 	    # Finalize command for both is simple: just hardcode it.
 	    if test yes = "$hardcode_direct" &&
 	       test no = "$hardcode_direct_absolute"; then
-	      add=$libdir/$linklib
+	      if test -f "$inst_prefix_dir$libdir/$linklib"; then
+		add="$inst_prefix_dir$libdir/$linklib"
+	      else
+		add="$libdir/$linklib"
+	      fi
 	    elif test yes = "$hardcode_minus_L"; then
 	      add_dir=-L$libdir
 	      add=-l$name
@@ -11201,7 +11208,7 @@ dlpreopen='$dlprefiles'
 
 # Directory that this library needs to be installed in:
 libdir='$install_libdir'"
-	  if test no,yes = "$installed,$need_relink"; then
+	  if test no,yes = "$installed,$need_relink" && test -n "$relink_command"; then
 	    $ECHO >> $output "\
 relink_command=\"$relink_command\""
 	  fi
