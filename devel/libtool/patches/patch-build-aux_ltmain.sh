$NetBSD: patch-build-aux_ltmain.sh,v 1.2 2018/11/13 21:44:42 sevan Exp $

Automatically generated using manual-* patches and bootstrap.
DO NOT MODIFY THIS PATCH MANUALLY!  YOUR CHANGES WILL BE LOST!

--- build-aux/ltmain.sh.orig	2018-11-13 09:14:27.768088590 +0000
+++ build-aux/ltmain.sh
@@ -309,6 +309,9 @@ test -z "$GREP" && {
 # uses them if a suitable command of that name is not already available
 # in the command search PATH.
 
+unset CP
+unset MV
+unset RM
 : ${CP="cp -f"}
 : ${ECHO="printf %s\n"}
 : ${EGREP="$GREP -E"}
@@ -2073,7 +2076,7 @@ include the following information:
        autoconf:       `($AUTOCONF --version) 2>/dev/null |$SED 1q`
 
 Report bugs to <bug-libtool@gnu.org>.
-GNU libtool home page: <http://www.gnu.org/software/libtool/>.
+GNU libtool home page: <http://www.gnu.org/s/libtool/>.
 General help using GNU software: <http://www.gnu.org/gethelp/>."
     exit 0
 }
@@ -8342,7 +8345,11 @@ func_mode_link ()
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
@@ -8865,6 +8872,7 @@ func_mode_link ()
 	# Calculate the version variables.
 	major=
 	versuffix=
+	versuffix2=
 	verstring=
 	case $version_type in
 	none) ;;
@@ -8935,6 +8943,7 @@ func_mode_link ()
 	  func_arith $current - $age
 	  major=.$func_arith_result
 	  versuffix=$major.$age.$revision
+	  versuffix2=$major.$age
 	  ;;
 
 	osf)
@@ -9000,8 +9009,10 @@ func_mode_link ()
 	  esac
 	  if test no = "$need_version"; then
 	    versuffix=
+	    versuffix2=
 	  else
 	    versuffix=.0.0
+	    versuffix2=.0.0
 	  fi
 	fi
 
@@ -9009,6 +9020,7 @@ func_mode_link ()
 	if test yes,no = "$avoid_version,$need_version"; then
 	  major=
 	  versuffix=
+	  versuffix2=
 	  verstring=
 	fi
 
@@ -9122,7 +9134,7 @@ func_mode_link ()
 	  *-*-netbsd*)
 	    # Don't link with libc until the a.out ld.so is fixed.
 	    ;;
-	  *-*-openbsd* | *-*-freebsd* | *-*-dragonfly*)
+	  *-*-openbsd* | *-*-freebsd* | *-*-dragonfly* | *-*-mirbsd*)
 	    # Do not include libc due to us having libc/libc_r.
 	    ;;
 	  *-*-sco3.2v5* | *-*-sco5v6*)
@@ -9145,12 +9157,14 @@ func_mode_link ()
 	libname_save=$libname
 	release_save=$release
 	versuffix_save=$versuffix
+	versuffix2_save=$versuffix2
 	major_save=$major
 	# I'm not sure if I'm treating the release correctly.  I think
 	# release should show up in the -l (ie -lgmp5) so we don't want to
 	# add it in twice.  Is that correct?
 	release=
 	versuffix=
+	versuffix2=
 	major=
 	newdeplibs=
 	droppeddeps=no
@@ -9427,6 +9441,7 @@ EOF
 	  ;;
 	esac
 	versuffix=$versuffix_save
+	versuffix2=$versuffix2_save
 	major=$major_save
 	release=$release_save
 	libname=$libname_save
@@ -10912,7 +10927,7 @@ dlpreopen='$dlprefiles'
 
 # Directory that this library needs to be installed in:
 libdir='$install_libdir'"
-	  if test no,yes = "$installed,$need_relink"; then
+	  if test no,yes = "$installed,$need_relink" && test -n "$relink_command"; then
 	    $ECHO >> $output "\
 relink_command=\"$relink_command\""
 	  fi
