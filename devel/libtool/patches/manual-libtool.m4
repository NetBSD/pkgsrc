$NetBSD: manual-libtool.m4,v 1.13 2005/03/22 15:12:08 tv Exp $

--- libtool.m4.orig	2005-02-12 07:18:34.000000000 -0500
+++ libtool.m4
@@ -346,11 +346,11 @@ else
 
   if test "X$echo" = Xecho; then
     # We didn't find a better echo, so look for alternatives.
-    if test "X`(print -r '\t') 2>/dev/null`" = 'X\t' &&
+    if test "X`(print -r - '\t') 2>/dev/null`" = 'X\t' &&
        echo_testing_string=`(print -r "$echo_test_string") 2>/dev/null` &&
        test "X$echo_testing_string" = "X$echo_test_string"; then
       # This shell has a builtin print -r that does the trick.
-      echo='print -r'
+      echo='print -r -'
     elif (test -f /bin/ksh || test -f /bin/ksh$ac_exeext) &&
 	 test "X$CONFIG_SHELL" != X/bin/ksh; then
       # If we have ksh, try running configure again with it.
@@ -1198,6 +1198,7 @@ beos*)
 bsdi[[45]]*)
   version_type=linux
   need_version=no
+  need_lib_prefix=no
   library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
   soname_spec='${libname}${release}${shared_ext}$major'
   finish_cmds='PATH="\$PATH:/sbin" ldconfig $libdir'
@@ -1315,15 +1316,16 @@ freebsd* | dragonfly*)
   # DragonFly does not have aout.  When/if they implement a new
   # versioning mechanism, adjust this.
   objformat=`test -x /usr/bin/objformat && /usr/bin/objformat || echo aout`
-  version_type=freebsd-$objformat
-  case $version_type in
-    freebsd-elf*)
-      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
+  version_type=linux
+  case $objformat in
+    elf*)
+      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
+      soname_spec='${libname}${release}${shared_ext}$major'
       need_version=no
       need_lib_prefix=no
       ;;
-    freebsd-*)
-      library_names_spec='${libname}${release}${shared_ext}$versuffix $libname${shared_ext}$versuffix'
+    *)  
+      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix2'
       need_version=yes
       ;;
   esac
@@ -1399,15 +1401,22 @@ hpux9* | hpux10* | hpux11*)
   postinstall_cmds='chmod 555 $lib'
   ;;
 
+interix3*)
+  version_type=linux
+  need_lib_prefix=no
+  need_version=no
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
+  soname_spec='${libname}${release}${shared_ext}$major'
+  dynamic_linker='Interix 3.x ld.so'
+  shlibpath_var=LD_LIBRARY_PATH
+  shlibpath_overrides_runpath=yes
+  hardcode_into_libs=yes
+  ;;
+
 irix5* | irix6* | nonstopux*)
   case $host_os in
     nonstopux*) version_type=nonstopux ;;
-    *)
-	if test "$lt_cv_prog_gnu_ld" = yes; then
-		version_type=linux
-	else
-		version_type=irix
-	fi ;;
+    *) version_type=irix ;;
   esac
   need_lib_prefix=no
   need_version=no
@@ -1484,11 +1493,11 @@ knetbsd*-gnu)
   ;;
 
 netbsd*)
-  version_type=sunos
+  version_type=linux
   need_lib_prefix=no
   need_version=no
   if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
-    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
+    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix2'
     finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
     dynamic_linker='NetBSD (a.out) ld.so'
   else
@@ -1519,10 +1528,10 @@ nto-qnx*)
   ;;
 
 openbsd*)
-  version_type=sunos
+  version_type=linux
   need_lib_prefix=no
   need_version=no
-  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix2'
   finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
   shlibpath_var=LD_LIBRARY_PATH
   if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
@@ -1687,9 +1696,7 @@ if test -f "$ltmain" && test -n "$tagnam
 
       case $tagname in
       CXX)
-	if test -n "$CXX" && ( test "X$CXX" != "Xno" &&
-	    ( (test "X$CXX" = "Xg++" && `g++ -v >/dev/null 2>&1` ) ||
-	    (test "X$CXX" != "Xg++"))) ; then
+        if test -n "$CXX" && test "X$CXX" != "Xno"; then
 	  AC_LIBTOOL_LANG_CXX_CONFIG
 	else
 	  tagname=""
@@ -2197,6 +2204,10 @@ hpux10.20* | hpux11*)
   esac
   ;;
 
+interix3*)
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|\.a)$'
+  ;;
+
 irix5* | irix6* | nonstopux*)
   case $LD in
   *-32|*"-32 ") libmagic=32-bit;;
@@ -2424,22 +2435,10 @@ AC_DEFUN([AC_LIBTOOL_CXX],
 # ---------------
 AC_DEFUN([_LT_AC_LANG_CXX],
 [AC_REQUIRE([AC_PROG_CXX])
-AC_REQUIRE([_LT_AC_PROG_CXXCPP])
+AC_REQUIRE([AC_PROG_CXXCPP])
 _LT_AC_SHELL_INIT([tagnames=${tagnames+${tagnames},}CXX])
 ])# _LT_AC_LANG_CXX
 
-# _LT_AC_PROG_CXXCPP
-# ---------------
-AC_DEFUN([_LT_AC_PROG_CXXCPP],
-[
-AC_REQUIRE([AC_PROG_CXX])
-if test -n "$CXX" && ( test "X$CXX" != "Xno" &&
-    ( (test "X$CXX" = "Xg++" && `g++ -v >/dev/null 2>&1` ) ||
-    (test "X$CXX" != "Xg++"))) ; then
-  AC_PROG_CXXCPP
-fi
-])# _LT_AC_PROG_CXXCPP
-
 # AC_LIBTOOL_F77
 # --------------
 # enable support for Fortran 77 libraries
@@ -2603,7 +2602,7 @@ AC_DEFUN([AC_LIBTOOL_LANG_CXX_CONFIG], [
 AC_DEFUN([_LT_AC_LANG_CXX_CONFIG],
 [AC_LANG_PUSH(C++)
 AC_REQUIRE([AC_PROG_CXX])
-AC_REQUIRE([_LT_AC_PROG_CXXCPP])
+AC_REQUIRE([AC_PROG_CXXCPP])
 
 _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
 _LT_AC_TAGVAR(allow_undefined_flag, $1)=
@@ -2935,7 +2934,7 @@ case $host_os in
           _LT_AC_TAGVAR(archive_cmds, $1)='$CC -qmkshrobj ${wl}-single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring'
           _LT_AC_TAGVAR(module_cmds, $1)='$CC $allow_undefined_flag -o $lib -bundle $libobjs $deplibs$compiler_flags'
           # Don't fix this by using the ld -exported_symbols_list flag, it doesn't exist in older darwin ld's
-          _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj ${wl}-single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}$rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
+          _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj ${wl}-single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           _LT_AC_TAGVAR(module_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC $allow_undefined_flag  -o $lib -bundle $libobjs $deplibs$compiler_flags~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           ;;
        *)
@@ -3093,6 +3092,16 @@ case $host_os in
 	;;
     esac
     ;;
+  interix3*)
+    # Oy, what a hack.
+    # Because shlibs are not compiled -fPIC due to broken code, we must
+    # choose an --image-base.  Otherwise, 0x10000000 will be chosen for
+    # all libraries, leading to runtime relocations -- slow and very
+    # memory consuming.  To do this, we pick a random 256KB-aligned
+    # start address between 0x50000000 and 0x6ffc0000 at link time.
+    _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+    _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed s,^,_, $export_symbols >$output_objdir/$soname.exp && $CC -shared $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file $wl$output_objdir/$soname ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+    ;;
   irix5* | irix6*)
     case $cc_basename in
       CC)
@@ -3222,14 +3231,29 @@ case $host_os in
     ;;
   netbsd*)
     if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
+      # a.out is quite broken and goes directly to ld
       _LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable  -o $lib $predep_objects $libobjs $deplibs $postdep_objects $linker_flags'
       wlarc=
+      # Determine if we need to override the c++rt0 that is
+      # picked up by analysing output_verbose_link_cmds
+      if test -f ${PREFIX}/lib/c++rt0/c++rt0.o.PIC; then
+        cpprt0_file="${PREFIX}/lib/c++rt0/c++rt0.o.PIC"
+      else
+        cpprt0_file=
+      fi
       _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
       _LT_AC_TAGVAR(hardcode_direct, $1)=yes
       _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
+    elif $CC -dumpspecs | grep -- '-lgcc -lc -lgcc' >/dev/null; then
+      # Workaround some broken pre-1.5 ELF toolchains
+      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
+    else
+      # Modern ELF works sanely as-is
+      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      output_verbose_link_cmd='echo'
     fi
-    # Workaround some broken pre-1.5 toolchains
-    output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
     ;;
   openbsd2*)
     # C++ shared libraries are fairly broken
@@ -3665,6 +3689,21 @@ if AC_TRY_EVAL(ac_compile); then
     esac
   done
 
+  case "$host_os" in
+  netbsd*)
+    if test -n "$cpprt0_file"; then
+      predep_objects_CXX=`eval echo $predep_objects_CXX | sed -e 's:/usr/lib/c++rt0.o:$cpprt0_file:'`
+    fi
+    ;;
+  interix3*)
+    # Interix installs completely hosed .la files for C++, so rather than
+    # hack all around it, let's just trust "g++" to DTRT.
+    predep_objects_CXX=
+    postdep_objects_CXX=
+    postdeps_CXX=
+    ;;
+  esac
+
   # Clean up.
   rm -f a.out a.exe
 else
@@ -4611,9 +4650,11 @@ AC_MSG_CHECKING([for $compiler option to
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'
       ;;
     darwin* | rhapsody*)
-      # PIC is the default on this platform
+      # PIC is the default on this platform, and static linking of
+      # binaries generally doesn't work
       # Common symbols not allowed in MH_DYLIB files
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)=''
       ;;
     *djgpp*)
       # DJGPP does not support shared libraries at all
@@ -4635,6 +4676,10 @@ AC_MSG_CHECKING([for $compiler option to
 	;;
       esac
       ;;
+    interix3*)
+      # Interix 3.0-3.5 -fPIC option generates borked code.
+      # (Instead, shlibs are relocated at runtime.)
+      ;;
     *)
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
       ;;
@@ -4709,6 +4754,8 @@ AC_MSG_CHECKING([for $compiler option to
 	    ;;
 	esac
 	;;
+      interix3*)
+	;;
       irix5* | irix6* | nonstopux*)
 	case $cc_basename in
 	  CC)
@@ -4880,9 +4927,11 @@ AC_MSG_CHECKING([for $compiler option to
       ;;
 
     darwin* | rhapsody*)
-      # PIC is the default on this platform
+      # PIC is the default on this platform, and static linking of
+      # binaries generally doesn't work
       # Common symbols not allowed in MH_DYLIB files
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)=''
       ;;
 
     msdosdjgpp*)
@@ -4911,6 +4960,11 @@ AC_MSG_CHECKING([for $compiler option to
       esac
       ;;
 
+    interix3*)
+      # Interix 3.0-3.5 -fPIC option generates borked code.
+      # (Instead, shlibs are relocated at runtime.)
+      ;;
+
     *)
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
       ;;
@@ -5225,6 +5279,17 @@ EOF
       fi
       ;;
 
+    interix3*)
+      # Oy, what a hack.
+      # Because shlibs are not compiled -fPIC due to broken code, we must
+      # choose an --image-base.  Otherwise, 0x10000000 will be chosen for
+      # all libraries, leading to runtime relocations -- slow and very
+      # memory consuming.  To do this, we pick a random 256KB-aligned
+      # start address between 0x50000000 and 0x6ffc0000 at link time.
+      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed s,^,_, $export_symbols >$output_objdir/$soname.exp && $CC -shared $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file $wl$output_objdir/$soname.exp ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+      ;;
+
     netbsd*)
       if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
 	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable $libobjs $deplibs $linker_flags -o $lib'
@@ -5528,7 +5593,7 @@ $echo "local: *; };" >> $output_objdir/$
          _LT_AC_TAGVAR(archive_cmds, $1)='$CC -qmkshrobj $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring'
          _LT_AC_TAGVAR(module_cmds, $1)='$CC $allow_undefined_flag -o $lib -bundle $libobjs $deplibs$compiler_flags'
           # Don't fix this by using the ld -exported_symbols_list flag, it doesn't exist in older darwin ld's
-         _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}$rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
+         _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           _LT_AC_TAGVAR(module_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC $allow_undefined_flag  -o $lib -bundle $libobjs $deplibs$compiler_flags~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           ;;
        *)
@@ -5643,6 +5708,21 @@ $echo "local: *; };" >> $output_objdir/$
       fi
       ;;
 
+    interix3*)
+      # Oy, what a hack.
+      # Because shlibs are not compiled -fPIC due to broken code, we must
+      # choose an --image-base.  Otherwise, 0x10000000 will be chosen for
+      # all libraries, leading to runtime relocations -- slow and very
+      # memory consuming.  To do this, we pick a random 256KB-aligned
+      # start address between 0x50000000 and 0x6ffc0000 at link time.
+      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed s,^,_, $export_symbols >$output_objdir/$soname.exp && $CC -shared $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file $wl$output_objdir/$soname ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-h,$libdir'
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
+
     irix5* | irix6* | nonstopux*)
       if test "$GCC" = yes; then
 	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
